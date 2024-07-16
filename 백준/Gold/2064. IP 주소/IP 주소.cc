#include <bits/stdc++.h>
using namespace std;

int n;
vector<bitset<32>> vec;

bitset<32> to_bitset(string str) {
  string buf;

  int val = 0b0;
  for (auto c : str) {
    if (c == '.') {
      val += stoi(buf);
      val = val << 8;
      buf = "";
    } else {
      buf += c;
    }
  }
  val += stoi(buf);
  bitset<32> bset(val);

  return bset;
}

string to_addr(bitset<32> bset) {
  string addr = "";

  auto it = bset.to_ullong();

  for (int i = 0; i < 4; i++) {
    int val = it % 256;

    addr = to_string(val) + addr;
    if (i < 3) addr = "." + addr;
    it /= 256;
  }

  return addr;
}

void solve() {
  string input;
  for (int i = 0; i < n; i++) {
    cin >> input;
    vec.push_back(to_bitset(input));
  }

  bitset<32> mask = bitset<32>(0b11111111111111111111111111111111);

  for (int i = 0; i < n; i++) {
    bitset<32> bset_i = vec[i];
    for (int j = i + 1; j < n; j++) {
      bitset<32> bset_j = vec[j];
      bitset<32> val = ~(bset_i ^ bset_j);
      mask = ~(bset_i ^ bset_j) & mask;
    }
  }

  bitset<32> ret_mask = bitset<32>();

  for (int i = 31; i >= 0; i--) {
    if (!mask.test(i)) break;
    ret_mask[i] = 0b1;
  }

  bitset<32> nw_addr = vec[0] & ret_mask;

  cout << to_addr(nw_addr) << "\n";
  cout << to_addr(ret_mask) << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n;

  solve();
}

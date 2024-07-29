#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n;
vector<pair<char, pii>> vec(101);  // {value, {l_idx, r_idx} }
string ans;

void recur(int idx) {
  auto p = vec[idx];
  if (p.second.first > 0) recur(p.second.first);
  ans += p.first;
  if (p.second.second > 0) recur(p.second.second);
}

vector<string> split(string str, char delimiter) {
  vector<string> ret;
  string buf = "";

  for (char c : str) {
    if (c == delimiter) {
      ret.push_back(buf);
      buf = "";
    } else {
      buf += c;
    }
  }
  ret.push_back(buf);
  return ret;
}

string solve() {
  ans = "";

  string input;
  getline(cin, input);
  n = stoi(input);

  for (int i = 0; i < n; i++) {
    getline(cin, input);

    char val;
    int idx, ll = 0, rr = 0;
    auto splitters = split(input, ' ');
    idx = stoi(splitters[0]);
    val = splitters[1][0];
    if (splitters.size() > 2) ll = stoi(splitters[2]);
    if (splitters.size() > 3) rr = stoi(splitters[3]);
    vec[idx] = {val, {ll, rr}};
  }

  recur(1);

  return ans;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  for (int test_case = 1; test_case <= 10; test_case++) {
    string sol = solve();
    cout << "#" << test_case << " " << sol << "\n";
  }
}

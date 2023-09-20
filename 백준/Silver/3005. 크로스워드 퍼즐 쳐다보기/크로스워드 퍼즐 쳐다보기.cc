#include <bits/stdc++.h>
using namespace std;

int r, c;
char arr[21][21] = {};
vector<string> vec;
void solve() {
  for (int j = 0; j < r; j++) {
    string mem;
    for (int i = 0; i < c; i++) {
      char cc = arr[j][i];
      if (cc == '#') {
        if (mem != "" && mem.size() >= 2) {
          vec.push_back(mem);
        }
        mem = "";
      } else {
        mem += cc;
      }
    }
    if (mem != "" && mem.size() >= 2) {
      vec.push_back(mem);
    }
  }

  for (int i = 0; i < c; i++) {
    string mem;
    for (int j = 0; j < r; j++) {
      char cc = arr[j][i];
      if (cc == '#') {
        if (mem != "" && mem.size() >= 2) {
          vec.push_back(mem);
        }
        mem = "";

      } else {
        mem += cc;
      }
    }
    if (mem != "" && mem.size() >= 2) {
      vec.push_back(mem);
    }
  }
  sort(vec.begin(), vec.end());
  cout << vec[0] << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> r >> c;
  string str;
  for (int j = 0; j < r; j++) {
    cin >> str;
    for (int i = 0; i < c; i++) {
      arr[j][i] = str[i];
    }
  }
  solve();
}

#include <bits/stdc++.h>
using namespace std;

void solve(string const s) {
  unordered_set<string> m;
  int length = s.size();
  string tmp;
  for (int l = 1; l <= length; l++) {
    for (int i = 0; i <= length - l; i++) {
      tmp.assign(s.begin() + i, s.begin() + i + l);
      m.insert(tmp);
    }
  }
  cout << m.size() << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  string s;  // input
  cin >> s;
  solve(s);
}

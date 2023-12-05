#include <bits/stdc++.h>
using namespace std;

string str;
int m[27] = {};

void solve() {
  for (auto c : str) {
    m[c - 'A']++;
  }
  char key = '*';

  string ans;
  for (int i = 0; i < 27; i++) {
    char c = ('A' + i);
    if (m[i] % 2 == 1) {
      if (key != '*') {
        cout << "I'm Sorry Hansoo\n";
        return;
      }
      key = c;
      m[i]--;
    }
    for (int j = 0; j < m[i] / 2; j++) {
      ans += c;
    }
  }
  string rev = ans;
  reverse(rev.begin(), rev.end());
  if (key != '*') ans += key;
  ans += rev;
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> str;
  solve();
}

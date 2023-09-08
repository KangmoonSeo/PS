#include <bits/stdc++.h>
using namespace std;

string str;
map<char, int> m;
int cnt[4] = {};

bool check() {
  int mem = 0;
  for (int i = 0; i < 4; i++) {
    if (cnt[i] != cnt[mem]) return false;
    mem = i;
  }
  return true;
}

void solve() {
  m['w'] = 0, m['o'] = 1, m['l'] = 2, m['f'] = 3;
  bool ans = true, isFinish = true;
  for (int i = 0; i < str.size(); i++) {
    if (!ans) break;
    int v = m[str[i]];
    cnt[v]++;

    if (v == 3 && m[str[i + 1]] == 0 && !check()) ans = false;

    int mem = 0;
    for (int i = 0; i < 4; i++) {
      if (cnt[i] > cnt[mem]) ans = false;
      mem = i;
    }

    for (int j = 0; j < 4; j++) {
      if (i == 0 || v != j) continue;
      int prev = m[str[i - 1]];
      if (prev != v && prev != (v + 3) % 4) ans = false;
    }
  }
  if (!check()) ans = false;

  cout << (ans ? "1\n" : "0\n");
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> str;
  solve();
}

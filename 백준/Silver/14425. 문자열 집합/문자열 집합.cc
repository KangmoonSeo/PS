#include <bits/stdc++.h>
using namespace std;

int n, m;
map<string, bool> ma;
void solve() {
  string str;
  for (int i = 0; i < n; i++) {
    cin >> str;
    ma[str] = true;
  }
  int ans = 0;
  for (int i = 0; i < m; i++) {
    cin >> str;
    if (ma[str]) ans++;
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n >> m;
  solve();
}

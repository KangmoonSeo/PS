#include <bits/stdc++.h>
using namespace std;

int n, m;
int d[201][201] = {};

void solve() {
  fill_n(d[0], 201 * 201, 1e9);
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= n; i++) {
      cin >> d[j][i];
      if (d[j][i] == 0) d[j][i] = 1e9;
    }
    d[j][j] = 0;
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (i == j) continue;
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  int u, v;
  for (int i = 0; i < m; i++) {
    cin >> v;
    if (i == 0) {
      u = v;
      continue;
    }
    if (d[u][v] > 1e8) {
      cout << "NO\n";
      return;
    }
    u = v;
  }
  cout << "YES\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n >> m;
  solve();
}

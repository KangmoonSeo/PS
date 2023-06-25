#include <bits/stdc++.h>
using namespace std;

int n, m, r;
int adj[101][101];
int item[101];

void floid() {
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (i == j) continue;
        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
      }
    }
  }
}
void solve() {
  floid();
  int ans = 0;
  for (int u = 1; u <= n; u++) {
    int sum = 0;
    for (int v = 1; v <= n; v++) {
      if (u != v && adj[u][v] > m) continue;
      sum += item[v];
    }
    ans = max(ans, sum);
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization
  fill_n(adj[0], 101 * 101, 1e8);
  cin >> n >> m >> r;
  for (int i = 1; i <= n; i++) {
    cin >> item[i];
  }
  int u, v, w;
  for (int i = 0; i < r; i++) {
    cin >> u >> v >> w;
    adj[u][v] = w;
    adj[v][u] = w;
  }
  solve();
}

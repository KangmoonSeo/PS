#include <bits/stdc++.h>
using namespace std;

int n, m, k, cost[10001], p[10001];
bool visited[10001] = {};

int find_root(int v) {
  if (p[v] == v) return p[v];
  p[v] = find_root(p[v]);

  return p[v];
}

void union_root(int u, int v) {
  int a = find_root(u);
  int b = find_root(v);
  if (a == b) return;
  if (cost[a] < cost[b]) swap(a, b);
  p[a] = b;
}

void solve() {
  int v, w;
  for (int i = 0; i < m; i++) {
    cin >> v >> w;
    union_root(v, w);
  }
  int ans = 0;

  for (int i = 1; i <= n; i++) {
    int root = find_root(i);
    if (visited[root]) continue;
    ans += cost[root];
    visited[root] = true;
  }
  if (k < ans) {
    cout << "Oh no\n";
  } else {
    cout << ans << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> cost[i];
    p[i] = i;
  }
  solve();
}
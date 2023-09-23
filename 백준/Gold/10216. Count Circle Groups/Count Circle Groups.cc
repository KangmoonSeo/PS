#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define x first
#define y second
int n;
pii p[3001];
int r[3001];
int parent[3001];
int h[3001] = {};

int find_root(int u) {
  if (parent[u] == u) return u;
  parent[u] = find_root(parent[u]);
  return parent[u];
}

void union_root(int u, int v) {
  u = find_root(u);
  v = find_root(v);
  if (u == v) return;
  if (h[u] < h[v]) swap(u, v);
  if (h[u] == h[v]) h[v]++;
  parent[u] = v;
}

void solve() {
  vector<pii> adj;

  for (int i = 1; i <= n; i++) {
    parent[i] = i;
    cin >> p[i].x >> p[i].y >> r[i];
  }
  for (int u = 1; u <= n; u++) {
    for (int v = u + 1; v <= n; v++) {
      int len = (p[u].x - p[v].x) * (p[u].x - p[v].x);
      len += (p[u].y - p[v].y) * (p[u].y - p[v].y);
      if (len <= (r[u] + r[v]) * (r[u] + r[v])) {
        adj.push_back({u, v});
      }
    }
  }
  for (pii it : adj) {
    union_root(it.first, it.second);
  }
  int ans = 0;
  bool visited[3001] = {};

  for (int i = 1; i <= n; i++) {
    int root = find_root(i);
    if (visited[root]) continue;
    visited[root] = true;
    ans++;
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    solve();
  }
}

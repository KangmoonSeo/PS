#include <bits/stdc++.h>
using namespace std;

int n, m;
int parent[500001];  // saves parent number
int node_rank[500001] = {};

int find_root(int u) {
  if (u == parent[u]) return u;
  return find_root(parent[u]);
}

void union_root(int u, int v) {
  if (node_rank[u] > node_rank[v]) swap(u, v);
  parent[u] = v;
  if (node_rank[u] == node_rank[v]) node_rank[v]++;
}

void solve() {
  for (int i = 0; i <= n; i++) {
    parent[i] = i;
  }
  int x1, x2;
  int ans = 0;
  bool isFinish = false;
  for (int i = 1; i <= m; i++) {
    cin >> x1 >> x2;
    if (isFinish) continue;

    int r1 = find_root(x1);
    int r2 = find_root(x2);
    if (r1 == r2) {
      ans = i;
      isFinish = true;
    } else {
      union_root(r1, r2);
    }
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n >> m;
  solve();
}

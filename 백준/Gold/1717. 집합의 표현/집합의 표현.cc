#include <bits/stdc++.h>
using namespace std;

int n, m;

int p[1000001];
int h[1000001] = {};

int find_root(int u) {
  if (p[u] == -1) return u;
  return find_root(p[u]);
}
pair<bool, pair<int, int> > check_root(int u, int v) {
  u = find_root(u);
  v = find_root(v);
  return {(u == v), {u, v}};
}

bool union_root(int u, int v) {
  pair<bool, pair<int, int> > pa = check_root(u, v);
  if (pa.first) return true;
  u = pa.second.first, v = pa.second.second;
  if (h[u] > h[v]) swap(u, v);
  p[u] = v;
  if (h[u] == h[v]) h[v]++;
  return false;
}

void solve() {
  fill_n(p, 1000001, -1);
  int f, u, v;
  while (m--) {
    cin >> f >> u >> v;
    if (f == 0) {
      union_root(u, v);
    } else {
      cout << (check_root(u, v).first ? "YES\n" : "NO\n");
    }
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n >> m;

  solve();
}

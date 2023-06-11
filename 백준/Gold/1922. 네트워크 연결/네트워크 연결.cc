#include <bits/stdc++.h>
using namespace std;

int p[1001];       // saves parent number
int h[1001] = {};  // height
int find_root(int u) {
  if (p[u] == -1) return u;
  p[u] = find_root(p[u]);
  return p[u];
}
bool union_root(int u, int v) {
  u = find_root(u);
  v = find_root(v);
  if (u == v) return true;
  if (h[u] > h[v]) swap(u, v);
  p[u] = v;
  if (h[u] == h[v]) h[v]++;
  return false;
}

typedef pair<int, pair<int, int> > pip;
priority_queue<pip, vector<pip>, greater<pip> > pq;
int n, m;
int ans = 0;

void solve() {
  // kruskal with disjoint set
  fill_n(p, 1001, -1);

  for (int i = 0; i < n - 1; i++) {
    pip e = pq.top();
    int w = e.first;
    int u = e.second.first;
    int v = e.second.second;
    pq.pop();

    if (union_root(u, v)) {
      i--;
      continue;
    }
    ans += w;
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n;
  cin >> m;
  int u, v, wei;
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> wei;
    pq.push(make_pair(wei, make_pair(u, v)));
  }

  solve();
}

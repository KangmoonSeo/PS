#include <bits/stdc++.h>

#include <tuple>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pipi;

int n, m;
int p[100001];       // saves parent number
int h[100001] = {};  // height
priority_queue<pipi, vector<pipi>, greater<pipi> > pq;

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

int ans = 0;
int maximum = 0;

void solve() {
  // 최소 신장 트리로 만들고, 그 중에 weight가 max인 edge 하나를 추가로 제거
  // kruskal
  fill_n(p, 100001, -1);

  for (int i = 0; i < n - 1; i++) {
    pipi e = pq.top();
    int w = e.first;
    int u = e.second.first;
    int v = e.second.second;
    pq.pop();

    if (union_root(u, v)) {
      i--;
      continue;
    }
    maximum = max(maximum, w);
    ans += w;
  }
  ans -= maximum;
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n >> m;
  int u, v, wei;
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> wei;
    pq.push(make_pair(wei, make_pair(u, v)));
  }

  solve();
}

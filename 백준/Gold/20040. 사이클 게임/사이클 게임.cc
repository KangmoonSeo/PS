#include <bits/stdc++.h>
using namespace std;

int n, m;
int p[500001];       // saves parent number
int h[500001] = {};  // height

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

void solve() {
  fill_n(p, 500001, -1);
  int x1, x2;
  int ans = 0;
  bool isFinish = false;
  for (int i = 1; i <= m; i++) {
    cin >> x1 >> x2;
    if (isFinish) continue;
    if (union_root(x1, x2)) {
      ans = i;
      isFinish = true;
    }
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n >> m;
  solve();
}

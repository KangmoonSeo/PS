#include <bits/stdc++.h>
using namespace std;

int p[101];  // parent
int h[101];  // height

int n, m;

void init() {
  for (int i = 1; i <= n; i++) {
    p[i] = i;
  }
  fill_n(h, 101, 1);
}

int get_parent(int x) {
  if (p[x] == x) return x;  // 내가 조상이다
  int nxt = get_parent(p[x]);
  p[x] = nxt;

  return p[x];
}

void connect(int u, int v) {
  //
  int pu = get_parent(u);
  int pv = get_parent(v);

  if (pu == pv) return;  // 이미 공통 조상

  if (h[pu] < h[pv]) {
    h[pu] += h[pv];
    p[pv] = pu;
  } else {
    h[pv] += h[pu];
    p[pu] = pv;
  }
}

int solve() {
  cin >> n >> m;
  init();

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    connect(u, v);
  }

  int ans = 0;
  bool visited[101] = {};

  for (int i = 1; i <= n; i++) {
    int x = get_parent(i);
    if (visited[x]) continue;
    visited[x] = true;
    ans++;
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  int T;
  cin >> T;
  for (int test_case = 1; test_case <= T; test_case++) {
    int ret = solve();
    cout << "#" << test_case << " " << ret << "\n";
  }
}

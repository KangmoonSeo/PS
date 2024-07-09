#include <bits/stdc++.h>
using namespace std;

int n;
int adj[12][12];
int bt[12];
bool visited[12];
int ans = 1e9;

void setInput() {
  cin >> n;
  vector<pair<int, int>> buf;  // 회사, 집, N명의 고객

  for (int i = 0; i < n + 2; i++) {
    int yy, xx;
    cin >> yy >> xx;
    buf.push_back({yy, xx});
  }
  for (int u = 0; u < n + 2; u++) {
    for (int v = u + 1; v < n + 2; v++) {
      int d =
          abs(buf[u].first - buf[v].first) + abs(buf[u].second - buf[v].second);
      adj[u][v] = d;
      adj[v][u] = adj[u][v];
    }
  }
}

void BT(int TTL = 0, int u = 0) {
  if (TTL == n) {
    int cnt = 0;
    for (int i = 0; i < n; i++) cnt += bt[i];
    cnt += adj[u][1];

    ans = min(ans, cnt);
    return;
  }

  for (int v = 2; v < n + 2; v++) {
    if (visited[v]) continue;
    bt[TTL] = adj[u][v];
    visited[v] = true;
    BT(TTL + 1, v);
    visited[v] = false;
  }
}

int solve() {
  setInput();
  fill_n(visited, 12, false);
  ans = 1e9;
  BT();
  return ans;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    int val = solve();
    cout << "#" << i << " " << val << "\n";
  }
}

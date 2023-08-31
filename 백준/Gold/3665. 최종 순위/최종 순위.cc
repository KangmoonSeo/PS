#include <bits/stdc++.h>
using namespace std;

int n, m, arr[501], d[501];
bool mat[501][501];
vector<int> adj[501];

void solve() {
  fill_n(d, 501, 0);
  fill_n(mat[0], 501 * 501, false);

  int u, v;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    adj[i] = vector<int>();
    cin >> arr[i];
  }
  for (int i = 1; i <= n; i++) {
    u = arr[i];
    for (int j = i + 1; j <= n; j++) {
      v = arr[j];
      mat[u][v] = true;
    }
  }

  bool err = false;
  cin >> m;
  while (m--) {
    cin >> u >> v;
    if (mat[u][v]) swap(u, v);
    mat[u][v] = true;
    mat[v][u] = false;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      if (mat[i][j]) {
        adj[i].push_back(j);
        d[j]++;
      }
    }
  }

  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (d[i] == 0) q.push(i);

    if (q.size() > 1) {
      err = true;
    }
  }

  vector<int> ans;
  while (!q.empty()) {
    int x = q.front();
    q.pop();

    ans.push_back(x);
    for (int nxt : adj[x]) {
      d[nxt]--;
      if (d[nxt] == 0) q.push(nxt);
    }
    if (q.size() > 1) {
      cout << "?\n";
      return;
    }
  }
  if (err || ans.size() < n) {
    cout << "IMPOSSIBLE\n";
    return;
  }
  for (auto it : ans) {
    cout << it << " ";
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}

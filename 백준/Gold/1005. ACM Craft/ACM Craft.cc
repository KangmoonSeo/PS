#include <bits/stdc++.h>
using namespace std;

int T, n, k, u, v, w;
int d[1001];
vector<int> adj[1001];
bool visited[1001];
int cnt[1001];
int dist[1001];

void solve() {
  fill_n(adj, 1001, vector<int>());
  fill_n(visited, 1001, false);
  fill_n(cnt, 1001, 0);
  fill_n(dist, 1001, 0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> d[i];
  }
  for (int i = 0; i < k; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    cnt[v]++;
  }
  cin >> w;

  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] == 0) {
      visited[i] = true;
      dist[i] = d[i];
      q.push(i);
    }
  }
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int nxt : adj[x]) {
      dist[nxt] = max(dist[nxt], dist[x] + d[nxt]);
      cnt[nxt]--;
      if (!visited[nxt] && cnt[nxt] == 0) {
        visited[nxt] = true;
        q.push(nxt);
      }
    }
    if (cnt[w] == 0) break;
  }
  int ans = dist[w];
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> T;
  while (T--) {
    solve();
  }
}

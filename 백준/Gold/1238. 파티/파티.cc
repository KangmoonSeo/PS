#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, m, x;
vector<pii> adj[1001];
vector<pii> rev[1001];
int result[1001] = {};

void dijkstra(vector<pii>* vec) {
  int dist[1001];
  fill_n(dist, 1001, 1e9);
  priority_queue<pii, vector<pii>, greater<pii> > pq;
  pq.push(make_pair(0, x));
  dist[x] = 0;
  while (!pq.empty()) {
    int cur = pq.top().second;
    int cur_dist = pq.top().first;
    pq.pop();
    if (dist[cur] < cur_dist) continue;
    for (pii p : vec[cur]) {
      int new_dist = p.first + cur_dist;
      if (new_dist < dist[p.second]) {
        dist[p.second] = new_dist;
        pq.push(make_pair(new_dist, p.second));
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    result[i] += dist[i];
  }
}
void solve() {
  int ans = 0;
  dijkstra(adj);
  dijkstra(rev);
  for (int i = 1; i <= n; i++) {
    ans = max(result[i], ans);
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n >> m >> x;
  int u, v, t;
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> t;
    adj[u].push_back(make_pair(t, v));
    rev[v].push_back(make_pair(t, u));
  }

  solve();
}

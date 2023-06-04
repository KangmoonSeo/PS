#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, e, v1, v2;
vector<pii> adj[801];
int dist[801];

int dijkstra(int start, int end) {
  fill_n(dist, 801, 1e9);
  priority_queue<pii, vector<pii>, greater<pii> > pq;
  pq.push(make_pair(0, start));
  dist[start] = 0;

  while (!pq.empty()) {
    int cur_dist = pq.top().first;
    int cur = pq.top().second;
    pq.pop();
    if (dist[cur] < cur_dist) continue;
    for (pii p : adj[cur]) {
      int nxt_dist = cur_dist + p.first;
      if (nxt_dist < dist[p.second]) {
        dist[p.second] = nxt_dist;
        pq.push(make_pair(nxt_dist, p.second));
      }
    }
  }
  return dist[end];
}

void solve() {
  int res1, res2;
  int a1 = dijkstra(1, v1);
  int a2 = dijkstra(v1, v2);
  int a3 = dijkstra(v2, n);
  if (a1 > 1e8 || a2 > 1e8 || a3 > 1e8)
    res1 = 1e9;
  else
    res1 = a1 + a2 + a3;

  int b1 = dijkstra(1, v2);
  int b2 = dijkstra(v2, v1);
  int b3 = dijkstra(v1, n);
  if (b1 > 1e8 || b2 > 1e8 || b3 > 1e8)
    res2 = 1e9;
  else
    res2 = b1 + b2 + b3;

  if (res1 > 1e8 && res2 > 1e8)
    cout << -1 << "\n";
  else
    cout << min(res1, res2) << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n >> e;
  int a, b, c;
  for (int i = 0; i < e; i++) {
    cin >> a >> b >> c;
    adj[a].push_back(make_pair(c, b));
    adj[b].push_back(make_pair(c, a));
  }
  cin >> v1 >> v2;

  solve();
}

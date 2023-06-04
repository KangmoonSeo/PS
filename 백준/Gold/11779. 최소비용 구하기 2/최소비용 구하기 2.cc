#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, m, s, e;
vector<pii> adj[1001];
int dist[1001];
int parent[1001] = {}; // 경로 역추적을 위한 각 정점의 부모 기록

void dijkstra(int start) {
  fill_n(dist, 1001, 1e9);
  priority_queue<pii, vector<pii>, greater<pii> > pq;
  pq.push(make_pair(0, start));
  dist[start] = 0;
  parent[start] = 0; // parent가 0번을 가르키면 시작점으로 간주
  while (!pq.empty()) {
    int cur_dist = pq.top().first;
    int cur = pq.top().second;
    pq.pop();
    if (cur_dist > dist[cur]) continue;
    for (pii p : adj[cur]) {
      int new_dist = p.first + cur_dist;
      if (new_dist < dist[p.second]) {
        dist[p.second] = new_dist;
        parent[p.second] = cur;  // dijkstra에서의 부모 추적 -> 경로
        pq.push(make_pair(new_dist, p.second));
      }
    }
  }
}
vector<int> traceParent() {
  vector<int> arr;
  int cur = e;
  while (cur != 0) { // parent가 0번을 가르키면 시작점
    arr.push_back(cur);
    cur = parent[cur];
  }
  return arr;
}

void solve() {
  // function acts here
  dijkstra(s);
  cout << dist[e] << "\n";
  vector<int> ans = traceParent();
  int length = ans.size();
  cout << length << "\n";
  for (int i = length - 1; i >= 0; i--) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n >> m;
  int u, v, w;
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> w;
    adj[u].push_back(make_pair(w, v));
  }
  cin >> s >> e;

  solve();
}

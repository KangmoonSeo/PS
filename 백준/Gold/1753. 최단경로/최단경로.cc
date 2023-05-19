#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define distance first
#define vertex second
#define MAX_V 20001
int n, m;  // n=V, m=E

void dijkstra() {
  vector<pii> adj[MAX_V];  // V개의 pii sequence를 저장하는 adj List
  int dist[MAX_V];
  fill_n(dist, MAX_V, 1e9);
  int start;
  cin >> start;
  int i1, i2, i3;  // start vertex, end vertex, direct distance
  while (m--) {
    cin >> i1 >> i2 >> i3;
    adj[i1].push_back(make_pair(i3, i2));  // { dist, vertex }
  };

  priority_queue<pii, vector<pii>, greater<pii> > pq;
  pq.push(make_pair(0, start));
  dist[start] = 0;

  while (!pq.empty()) {
    int cur_dist = pq.top().distance;  // queue에서 제일 작은 distance
    int cur = pq.top().vertex;  // queue에서 distance가 제일 작은 pair의 vertex
    pq.pop();

    // 저장된 dist가 queue에서 꺼낸 dist보다 작으면 skip
    if (dist[cur] < cur_dist) continue;

    for (pii p : adj[cur]) {
      // i->cur까지의 거리 후보 = i->p.vertex 거리 + p.vertex->cur 거리
      int new_dist = p.distance + cur_dist;
      if (new_dist < dist[p.vertex]) {  // 새 dist가 저장된 dist보다 작으면 갱신
        dist[p.vertex] = new_dist;
        pq.push(make_pair(new_dist, p.vertex));  // queue에 pair push
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << (dist[i] != 1e9 ? to_string(dist[i]) : "INF") << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n >> m;
  dijkstra();
}

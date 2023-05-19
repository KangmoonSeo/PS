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
  int i_s, i_e, i_d;  // i_start, i_end, i_distance
  while (m--) {
    cin >> i_s >> i_e >> i_d;
    adj[i_s].push_back(make_pair(i_d, i_e));  // { dist, vertex }
  };

  priority_queue<pii, vector<pii>, greater<pii> > pq;
  pq.push(make_pair(0, start));
  dist[start] = 0;

  while (!pq.empty()) {
    pii p = pq.top();
    pq.pop();
    // 저장된 dist가 queue에서 꺼낸 값보다 작으면 skip
    if (dist[p.vertex] < p.distance) continue;

    for (pii it : adj[p.vertex]) {  // dist를 최소로 만들기 위한 loop
      int nxt = it.vertex;
      if (it.distance + p.distance < dist[nxt]) {
        dist[nxt] = it.distance + p.distance;  // dist update
        pq.push(make_pair(dist[nxt], nxt));    // queue에 pair push
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

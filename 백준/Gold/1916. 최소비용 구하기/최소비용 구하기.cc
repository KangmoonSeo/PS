#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define distance first
#define vertex second
#define MAX_V 1001
int n, m;  // n=V, m=E

void dijkstra() {
  vector<pii> adj[MAX_V];  // V개의 pii sequence를 저장하는 adj List
  int dist[MAX_V];
  fill_n(dist, MAX_V, 1e9);

  int i_s, i_e, i_d;  // i_start, i_end, i_distance
  while (m--) {
    cin >> i_s >> i_e >> i_d;
    adj[i_s].push_back(make_pair(i_d, i_e));  // { dist, vertex }
  };
  int start, end;
  cin >> start >> end;

  priority_queue<pii, vector<pii>, greater<pii> > pq;
  pq.push(make_pair(0, start));
  dist[start] = 0;

  while (!pq.empty()) {
    int cur = pq.top().vertex;
    int curdist = pq.top().distance;
    pq.pop();

    // 현재 distance가 저장된 dist보다 작으면 loop 진행
    if (curdist > dist[cur]) continue;

    int length = adj[cur].size();
    for (auto it : adj[cur]) {
      int nxt = it.vertex;
      int nxtdist = it.distance + curdist;
      if (nxtdist < dist[nxt]) {
        dist[nxt] = nxtdist;                 // distance update
        pq.push(make_pair(dist[nxt], nxt));  // queue에 pair push
      }
    }
  }
  cout << dist[end] << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n >> m;
  dijkstra();
}

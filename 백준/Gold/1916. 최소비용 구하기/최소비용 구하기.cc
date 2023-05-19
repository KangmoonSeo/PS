#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define distance first
#define vertex second
#define MAX_V 1001
int n, m;

void dijkstra() {
  vector<pii> adj[MAX_V];
  int dist[MAX_V];
  fill_n(dist, MAX_V, 1e9);

  int ss, ee, dd;
  while (m--) {
    cin >> ss >> ee >> dd;
    adj[ss].push_back(make_pair(dd, ee));  // { dist, vertex }
  };
  int start, end;
  cin >> start >> end;

  priority_queue<pii, vector<pii>, greater<pii> > pq;
  pq.push(make_pair(0, start));  // { dist, vertex }
  dist[start] = 0;

  while (!pq.empty()) {
    int cur = pq.top().vertex;
    int curdist = pq.top().distance;
    pq.pop();

    // 현재 distance가 저장된 dist보다 작으면 loop 진행
    if (curdist > dist[cur]) continue;

    int length = adj[cur].size();
    for (int i = 0; i < length; i++) {
      int nxt = adj[cur][i].vertex;
      int nxtdist = curdist + adj[cur][i].distance;

      // (nxtdist < 저장된 값) 이면 저장값 update, queue에 push
      if (nxtdist < dist[nxt]) {
        dist[nxt] = nxtdist;
        pq.push(make_pair(dist[nxt], nxt));
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

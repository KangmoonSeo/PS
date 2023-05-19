#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define _dist first
#define _v second
#define MAX_V 1001
#define MAX_W 1e9
int n, m;

void dijkstra() {
  vector<vector<pii> > adj(MAX_V);
  vector<int> dist(MAX_V, MAX_W);

  int ss, ee, dd;
  while (m--) {
    cin >> ss >> ee >> dd;
    adj[ss].push_back(make_pair(dd, ee));
  };
  int init, end;
  cin >> init >> end;

  priority_queue<pii, vector<pii>, greater<pii> > pq;  // { dist, vertex }
  pq.push(make_pair(0, init));
  dist[init] = 0;

  while (!pq.empty()) {
    int cur = pq.top()._v;
    int curdist = pq.top()._dist;
    pq.pop();

    if (curdist > dist[cur]) continue;  // curdist가 저장값보다 작으면 진행

    int length = adj[cur].size();
    for (int i = 0; i < length; i++) {
      int nxt = adj[cur][i]._v;
      int nxtdist = curdist + adj[cur][i]._dist;

      // nxtdist가 저장값보다 작으면 push
      if (dist[nxt] > curdist + adj[cur][i]._dist) {
        dist[nxt] = curdist + adj[cur][i]._dist;
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

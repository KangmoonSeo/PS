#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, k;
int dist[200003];

void solve() {
  fill_n(dist, 200001, 1e9);
  priority_queue<pii, vector<pii>, greater<pii> > pq;
  pq.push(make_pair(0, n));
  dist[n] = 0;
  while (!pq.empty()) {
    int cnt = pq.top().first;
    int x = pq.top().second;
    pq.pop();
    if (dist[x] < cnt) continue;

    int nx;
    nx = x * 2;
    if (nx >= 0 && nx <= 200001 && dist[nx] > cnt) {
      dist[nx] = cnt;
      pq.push(make_pair(dist[nx], nx));
    }
    nx = x - 1;
    if (nx >= 0 && nx <= 200001 && dist[nx] > cnt + 1) {
      dist[nx] = cnt + 1;
      pq.push(make_pair(dist[nx], nx));
    }
    nx = x + 1;
    if (nx >= 0 && nx <= 200001 && dist[nx] > cnt + 1) {
      dist[nx] = cnt + 1;
      pq.push(make_pair(dist[nx], nx));
    }
  }
  cout << dist[k] << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n >> k;
  solve();
}

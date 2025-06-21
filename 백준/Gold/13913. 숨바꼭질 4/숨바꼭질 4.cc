#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int n, k;
int parent[200001];
int dist[200001];
queue<pii> q;

/**
 * n: 수빈의 점, n in [0, 100,000]
 * k: 동생의 점, k in [0, 100,000]
 *
 * 선택지: x+1, x-1, x+x
 *
 * dist_i : dist까지 도달하는 데에 걸리는 시간, 작을 때 갱신
 */

void solve() {
  // function works here
  fill_n(dist, 200001, 1e9);

  q.push({0, n});
  dist[n] = 0;
  parent[n] = n;

  while (!q.empty()) {
    pii p = q.front();
    q.pop();
    int cnt = p.first;
    int x = p.second;
    if (x == k) {
      break;
    }

    int nx = x * 2;
    if (nx >= 0 && nx <= 200000 && dist[nx] > cnt + 1) {
      dist[nx] = cnt + 1;
      q.push({dist[nx], nx});
      parent[nx] = x;
    }

    nx = x + 1;
    if (nx >= 0 && nx <= 200000 && dist[nx] > cnt + 1) {
      dist[nx] = cnt + 1;
      q.push({dist[nx], nx});
      parent[nx] = x;
    }

    nx = x - 1;
    if (nx >= 0 && nx <= 200000 && dist[nx] > cnt + 1) {
      dist[nx] = cnt + 1;
      q.push({dist[nx], nx});
      parent[nx] = x;
    }
  }

  int idx = k;
  vector<int> rev;
  while (true) {
    rev.push_back(idx);
    idx = parent[idx];
    if (idx == n) break;
  }
  if (dist[k] > 0) {
    rev.push_back(idx);
  }

  cout << dist[k] << "\n";
  for (int i = rev.size() - 1; i >= 0; i--) {
    cout << rev[i] << " ";
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n >> k;
  solve();
}

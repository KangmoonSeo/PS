#include <bits/stdc++.h>
using namespace std;

int n, m, w;  // n: 지점의 수, m: 도로 개수, w: 웜홀 개수
int dist[501];
bool visited[501];

int bellman(int start, vector<vector<int> > adj) {
  fill_n(dist, 501, 1e9);
  dist[start] = 0;
  for (int k = 1; k <= n; k++) {
    for (int cur = 1; cur <= n; cur++) {
      if (dist[cur] > 1e8) continue;
      visited[cur] = true;
      for (int i = 1; i <= n; i++) {
        if (adj[cur][i] > 1e8) continue;
        visited[i] = true;
        int n_dist = dist[cur] + adj[cur][i];
        if (n_dist < dist[i]) {
          dist[i] = n_dist;
          if (k == n) return -1;
        }
      }
    }
  }
  return 1;
}
void solve() {
  cin >> n >> m >> w;
  vector<vector<int> > adj(n + 1, vector<int>(n + 1, 1e9));
  fill_n(visited, 501, true);

  int s, e, t;
  for (int i = 0; i < m + w; i++) {  // 도로, 웜홀
    cin >> s >> e >> t;
    if (i < m) {
      adj[s][e] = min(adj[s][e], t);
      adj[e][s] = min(adj[e][s], t);
    } else {
      adj[s][e] = min(adj[s][e], -t);
      visited[s] = false;
    }
  }

  for (int i = 1; i <= 500; i++) {
    if (!visited[i] && bellman(i, adj) < 0) {  // 과거로 돌아가는 케이스
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}

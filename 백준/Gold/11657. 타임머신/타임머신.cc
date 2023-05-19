#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, int> pii;
#define cost first
#define vertex second
#define MAX_V 501
int n, m;  // n=V, m=E

vector<pii> adj[MAX_V];
long long dist[MAX_V];

int bellman(int start) {
  fill_n(dist, MAX_V, 1e9);

  int i1, i2, i3;  // start vertex, end vertex, direct cost
  while (m--) {
    cin >> i1 >> i2 >> i3;
    adj[i1].push_back(make_pair(i3, i2));  // { dist, vertex }
  };

  dist[start] = 0;

  for (int i = 1; i <= n; i++) {
    for (int cur = 1; cur <= n; cur++) {
      if (dist[cur] == 1e9) continue;
      for (pii el : adj[cur]) {
        int next = el.vertex;
        long long nextCost = el.cost + dist[cur];
        if (dist[next] > nextCost) {
          dist[next] = nextCost;
          if (i == n) return -1;  // 음수 사이클 발생
        }
      }
    }
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n >> m;
  if (bellman(1) == -1) {
    cout << "-1\n";
  } else {
    for (int i = 2; i <= n; i++) {
      cout << (dist[i] != 1e9 ? dist[i] : -1) << "\n";
    }
  }
}

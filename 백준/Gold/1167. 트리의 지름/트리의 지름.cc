#include <bits/stdc++.h>
#define child first
#define weight second
using namespace std;

int n;
vector<pair<int, int> > adj[100001];  // contains {child, weight}
bool visited[100001] = {};
int ans = 0;

int dfs(int v) {
  int length = adj[v].size();
  int dist = 0;
  int mem = 0;

  for (int i = 0; i < length; i++) {
    pair<int, int> p = adj[v][i];
    if (visited[p.child]) continue;
    visited[p.child] = true;
    int d = dfs(p.child);  // get dist from p.child
    int n_dist = d + p.weight;
    if (dist < n_dist) {
      mem = dist;
      dist = n_dist;
    } else {
      mem = max(mem, n_dist);
    }
  }
  ans = max(dist + mem, ans);
  return dist;
}
void solve() {
  int par, chi, wei;
  for (int i = 1; i <= n; i++) {
    cin >> par;  // par == i
    cin >> chi;
    while (chi > 0) {
      cin >> wei;
      adj[par].push_back(make_pair(chi, wei));
      cin >> chi;
    }
  }
  visited[1] = true;
  dfs(1);

  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n;
  solve();
}

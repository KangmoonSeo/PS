#include <bits/stdc++.h>
#define child first
#define weight second
using namespace std;

int n;
vector<pair<int, int> > nodes[100001];  // contains {child, weight}
int l[100001] = {};
int r[100001] = {};
bool visited[100001] = {};
int ans = 0;

void dfs(int v) {
  int length = nodes[v].size();
  for (int i = 0; i < length; i++) {
    pair<int, int> p = nodes[v][i];
    if (visited[p.child]) continue;
    visited[p.child] = true;
    dfs(p.child);  // get l[p.child]
    int n_l = l[p.child] + p.weight;
    if (l[v] < n_l) {
      r[v] = l[v];
      l[v] = n_l;
    } else {
      r[v] = max(r[v], n_l);
    }
  }
  ans = max(l[v] + r[v], ans);
}
void solve() {
  int par, chi, wei;
  for (int i = 1; i <= n; i++) {
    cin >> par;  // par == i
    cin >> chi;
    while (chi > 0) {
      cin >> wei;
      nodes[par].push_back(make_pair(chi, wei));
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

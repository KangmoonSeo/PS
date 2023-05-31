#include <bits/stdc++.h>
#define child first
#define weight second
using namespace std;

int n;
vector<pair<int, int> > nodes[10001];  // contains {child, weight}
int l[10001] = {};
int r[10001] = {};
int sum[10001] = {};
int ans = 0;

void dfs(int v) {
  int length = nodes[v].size();
  for (int i = 0; i < length; i++) {
    pair<int, int> p = nodes[v][i];
    dfs(p.child);  // get l[p.child]
    int n_l = l[p.child] + p.weight;
    if (l[v] < n_l) {
      r[v] = l[v];
      l[v] = n_l;
    } else {
      r[v] = max(r[v], n_l);
    }
  }
  sum[v] = l[v] + r[v];
  ans = max(sum[v], ans);
}
void solve() {
  int par, chi, wei;
  for (int i = 0; i < n - 1; i++) {
    cin >> par >> chi >> wei;
    nodes[par].push_back(make_pair(chi, wei));
  }
  dfs(1);

  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n;
  solve();
}

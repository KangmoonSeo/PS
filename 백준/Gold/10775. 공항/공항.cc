#include <bits/stdc++.h>
using namespace std;

int n, p, parent[100001] = {};

int find(int v) {
  if (v == parent[v]) return v;
  parent[v] = find(parent[v]);
  return parent[v];
}
void solve() {
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    parent[i] = i;
  }
  bool fl = false;
  int g;
  for (int i = 1; i <= p; i++) {
    cin >> g;
    if (fl) continue;
    int root = find(g);
    if (root == 0) {
      fl = true;
      continue;
    }
    ans++;
    parent[root] = find(root - 1);
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n >> p;

  solve();
}

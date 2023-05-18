#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int> > adj(100001, vector<int>());
vector<int> parent(100001, 0);

void dfs(int v) {
  if (parent[v] == 0) return;
  vector<int> vec = adj[v];
  int length = vec.size();
  for (int i = 0; i < length; i++) {
    int t = vec[i];
    if (parent[t] == 0) {
      parent[t] = v;
      dfs(t);
    }
  }
}

void solve() {
  int i1, i2;
  for (int i = 0; i < n - 1; i++) {
    cin >> i1 >> i2;
    adj[i1].push_back(i2);
    adj[i2].push_back(i1);
  }
  parent[1] = 1;
  for (int k = 1; k <= n; k++) {
    dfs(k);
  }
  for (int k = 2; k <= n; k++) {
    cout << parent[k] << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n;
  solve();
}

#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<int> adj[100001];
int d[100001];
bool finished[100001];
vector<int> vec;
vector<vector<int>> SCC;
int id;

bool cmp(vector<int> a, vector<int> b) { return a[0] < b[0]; }

int tarjan(int u) {
  //
  id++;
  d[u] = id;
  vec.push_back(u);

  int parent = d[u];
  for (auto v : adj[u]) {
    if (d[v] == 0) {  // 방문하지 않은 adj
      parent = min(parent, tarjan(v));
    } else if (!finished[v]) {  // 처리 중인 adj
      parent = min(parent, d[v]);
    }
  }
  // 부모노드가 자기 자신인 경우
  if (parent == d[u]) {
    vector<int> scc;
    while (true) {
      int t = vec.back();
      vec.pop_back();
      scc.push_back(t);
      finished[t] = true;
      if (t == u) break;
    }
    SCC.push_back(scc);
  }
  return parent;
}

void solve() {
  fill_n(adj, (n + 1), vector<int>());
  fill_n(finished, (n + 1), false);
  fill_n(d, (n + 1), 0);
  SCC.clear();
  id = 0;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
  for (int i = 1; i <= n; i++) {
    if (d[i] == 0) tarjan(i);
  }

  cout << SCC.size() << "\n";
  //

  for (auto& scc : SCC) {
    sort(scc.begin(), scc.end());
  }
  sort(SCC.begin(), SCC.end(), cmp);

  for (auto& scc : SCC) {
    for (auto i : scc) {
      cout << i << " ";
    }
    cout << "-1\n";
  }
  //
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n >> m;
  solve();
}

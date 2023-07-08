#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[32001];
int cnt[32001] = {};

void solve() {
  int u, v;
  while (m--) {
    cin >> u >> v;
    if (u == v) continue;
    cnt[v]++;
    adj[u].push_back(v);
  }
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] == 0) q.push(i);
  }

  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int it : adj[cur]) {
      cnt[it]--;
      if (cnt[it] == 0) q.push(it);
    }
    cout << cur << " ";
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n >> m;

  solve();
}

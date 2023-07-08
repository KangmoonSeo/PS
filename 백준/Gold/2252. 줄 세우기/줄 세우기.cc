#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, m;
vector<int> adj[32001];
int cnt[32001] = {};
bool visited[32001] = {};
vector<int> seq;

int find() {
  for (int i = 1; i <= n; i++) {
    if (!visited[i] && cnt[i] == 0) return i;
  }
  return -1;
}

void solve() {
  int u, v;
  while (m--) {
    cin >> u >> v;
    if (u == v) continue;
    cnt[v]++;
    adj[u].push_back(v);
  }

  for (int i = 0; i < n; i++) {
    int cur = find();
    visited[cur] = true;
    seq.push_back(cur);
    for (int it : adj[cur]) {
      cnt[it]--;
    }
  }

  for (int it : seq) {
    cout << it << " ";
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n >> m;

  solve();
}

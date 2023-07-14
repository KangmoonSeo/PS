#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[32001];
int cnt[32001] = {};
vector<int> ans;
void solve() {
  // function works here
  while (m--) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    cnt[v]++;
  }
  priority_queue<int, vector<int>, greater<int> > pq;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] == 0) pq.push(i);
  }
  while (!pq.empty()) {
    int x = pq.top();
    pq.pop();
    ans.push_back(x);

    for (int it : adj[x]) {
      cnt[it]--;
      if (cnt[it] == 0) {
        pq.push(it);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n >> m;
  solve();
}

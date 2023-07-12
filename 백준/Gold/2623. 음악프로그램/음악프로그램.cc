#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1001];
int cnt[1001] = {};
void solve() {
  for (int i = 0; i < m; i++) {
    int num, u, v;
    cin >> num;
    num--;
    cin >> u;
    while (num--) {
      cin >> v;
      adj[u].push_back(v);
      cnt[v]++;
      swap(u, v);
    }
  }
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] == 0) q.push(i);
  }
  vector<int> ans;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    ans.push_back(x);
    for (int it : adj[x]) {
      cnt[it]--;
      if (cnt[it] == 0) {
        q.push(it);
      }
    }
  }
  if (ans.size() < n) {
    cout << "0\n";
  } else {
    for (int it : ans) {
      cout << it << "\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n >> m;
  solve();
}

#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int> > adj(100001, vector<int>());
vector<int> parent(100001, 0);

void solve() {
  // input
  int i1, i2;
  for (int i = 0; i < n - 1; i++) {
    cin >> i1 >> i2;
    adj[i1].push_back(i2);
    adj[i2].push_back(i1);
  }
  // bfs
  queue<int> q;
  parent[1] = 1;
  q.push(1);
  while (!q.empty()) {
    int p = q.front();
    q.pop();
    vector<int> vec = adj[p];
    int length = vec.size();
    for (int i = 0; i < length; i++) {
      int t = vec[i];
      if (parent[t] == 0) {
        parent[t] = p;
        q.push(t);
      }
    }
  }
  // output
  for (int k = 2; k <= n; k++) {
    cout << parent[k] << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n;
  solve();
}

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[100001];
vector<int> pa(100001, 0);

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
  pa[1] = 1;
  q.push(1);
  while (!q.empty()) {
    int p = q.front();
    q.pop();

    for (auto it : adj[p]) {
      if (pa[it] == 0) {
        pa[it] = p;
        q.push(it);
      }
    }
  }
  // output
  for (int k = 2; k <= n; k++) {
    cout << pa[k] << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n;
  solve();
}

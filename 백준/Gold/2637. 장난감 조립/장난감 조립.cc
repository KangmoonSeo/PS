#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, m;
int mat[101][101] = {};
bool isBasic[101] = {};

void convert_to_basic(int v) {
  if (isBasic[v]) return;
  for (int i = 1; i <= n; i++) {
    if (mat[v][i] == 0 || isBasic[i]) continue;
    for (int j = 1; j <= n; j++) {
      if (mat[i][j] == 0) continue;
      mat[v][j] += mat[v][i] * mat[i][j];
    }
    mat[v][i] = 0;
  }
}

void solve() {
  int u, v, w, d[101] = {};

  vector<int> adj[101];

  while (m--) {
    cin >> u >> v >> w;
    adj[v].push_back(u);
    mat[u][v] = w;
    d[u]++;
  }

  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (d[i] == 0) {
      isBasic[i] = true;
      mat[i][i] = 1;
      q.push(i);
    }
  }
  vector<int> seq;  // results of topolocical sorting
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    seq.push_back(x);
    for (int nxt : adj[x]) {
      if (--d[nxt] == 0) q.push(nxt);
    }
  }

  int last = -1;
  for (int it : seq) {
    convert_to_basic(it);
    last = it;
  }
  for (int i = 1; i <= n; i++) {
    if (mat[last][i] == 0) continue;
    cout << i << " " << mat[last][i] << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n >> m;
  solve();
}

#include <bits/stdc++.h>
using namespace std;

int n, arr[10][10];
bool visited[10];

long long ans = 1e9L;
long long dist = 0;

void BT(int u, int TTL, int init) {
  if (TTL >= n) {
    if (arr[u][init] == 0) return;
    dist += arr[u][init];
    ans = min(ans, dist);
    dist -= arr[u][init];
    return;
  }

  for (int v = 0; v < n; v++) {
    if (visited[v]) continue;
    if (arr[u][v] == 0) continue;
    dist += arr[u][v];
    visited[v] = true;
    BT(v, TTL + 1, init);
    dist -= arr[u][v];
    visited[v] = false;
  }
}
void solve() {
  // function works here
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < n; i++) {
      cin >> arr[j][i];
    }
  }

  for (int i = 0; i < n; i++) {
    visited[i] = true;
    BT(i, 1, i);
    visited[i] = false;
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n;
  solve();
}

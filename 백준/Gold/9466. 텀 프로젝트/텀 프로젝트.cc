#include <bits/stdc++.h>
using namespace std;

int n, cnt;
bool visited[100001];
bool traced[100001];
int arr[100001];

void dfs(int v) {
  visited[v] = true;
  int nxt = arr[v];
  if (!visited[nxt]) {
    dfs(arr[v]);
  } else if (!traced[nxt]) {
    for (int i = nxt; i != v; i = arr[i]) {
      cnt++;
    }
    cnt++;
  }
  traced[v] = true;
}

void solve() {
  cin >> n;
  cnt = 0;
  fill_n(visited, n + 1, false);
  fill_n(traced, n + 1, false);

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) dfs(i);
  }

  int ans = n - cnt;
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}

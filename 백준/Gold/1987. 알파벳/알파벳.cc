#include <bits/stdc++.h>
const int dy[4] = {1, 0, -1, 0};
const int dx[4] = {0, 1, 0, -1};
using namespace std;
typedef pair<int, int> pii;
bool bt[26] = {};
int r, c;
int arr[22][22] = {};  // [0, 27)
int ans = 0;
bool dfs(int TTL, pii p) {
  ans = max(ans, TTL);
  if (TTL >= 26) return true;

  for (int i = 0; i < 4; i++) {
    int ny = dy[i] + p.first;
    int nx = dx[i] + p.second;
    int val = arr[ny][nx];
    if (bt[val]) continue;
    bt[val] = true;
    if (dfs(TTL + 1, make_pair(ny, nx))) return true;
    bt[val] = false;
  }
  return false;
}
void solve() {
  bt[0] = true;
  bt[arr[1][1]] = true;
  // DFS with BT
  dfs(1, make_pair(1, 1));
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization
  cin >> r >> c;
  string input;
  for (int j = 1; j <= r; j++) {
    cin >> input;
    for (int i = 1; i <= c; i++) {
      arr[j][i] = input[i - 1] - 'A' + 1;
    }
  }
  solve();
}

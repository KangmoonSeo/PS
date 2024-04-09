#include <bits/stdc++.h>
using namespace std;

int H, W, arr[502][502], dp[502][502] = {};
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int dfs(int y, int x) {
  if (y == H && x == W) return 1;

  if (dp[y][x] > -1) return dp[y][x];
  dp[y][x] = 0;

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (arr[y][x] <= arr[ny][nx]) continue;
    dp[y][x] += dfs(ny, nx);
  }
  return dp[y][x];
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */
  fill_n(arr[0], 502 * 502, 1e6);
  fill_n(dp[0], 502 * 502, -1);

  int m, n;
  cin >> m >> n;
  H = m, W = n;

  for (int j = 1; j <= H; j++) {
    for (int i = 1; i <= W; i++) {
      cin >> arr[j][i];
    }
  }

  cout << dfs(1, 1) << "\n";
}

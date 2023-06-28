#include <bits/stdc++.h>
#define y first
#define x second
using namespace std;
typedef pair<int, int> pii;

int n;
int arr[18][18];
int dp[3][18][18] = {};  // 0: --, 1: \, 2: |

void solve() {
  int i = 0;
  bool fl = false;
  dp[0][1][2] = 1;
  while (!fl && i < 2 * n) {
    i++;
    for (int j = 0; j < i; j++) {
      pii p = {1 + j, 2 + i - j};
      if (p.y == n && p.x == n) fl = true;
      if (p.y > n || p.y < 1 || p.x > n || p.x < 2) continue;
      if (arr[p.y][p.x] > 0) continue;
      for (int k = 0; k < 3; k++) {
        if (k == 0) {  // --
          if (arr[p.y][p.x - 1] > 0) continue;
          dp[k][p.y][p.x] += dp[0][p.y][p.x - 1];
          dp[k][p.y][p.x] += dp[1][p.y][p.x - 1];
        } else if (k == 1) {  // \.
          if (arr[p.y - 1][p.x - 1] > 0 || arr[p.y - 1][p.x] > 0 ||
              arr[p.y][p.x - 1] > 0)
            continue;

          dp[k][p.y][p.x] += dp[0][p.y - 1][p.x - 1];
          dp[k][p.y][p.x] += dp[1][p.y - 1][p.x - 1];
          dp[k][p.y][p.x] += dp[2][p.y - 1][p.x - 1];
        } else if (k == 2) {  // |
          if (arr[p.y - 1][p.x] > 0) continue;

          dp[k][p.y][p.x] += dp[1][p.y - 1][p.x];
          dp[k][p.y][p.x] += dp[2][p.y - 1][p.x];
        }
      }
    }
  }
  int ans = dp[0][n][n] + dp[1][n][n] + dp[2][n][n];
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n;
  fill_n(arr[0], 18 * 18, 1);
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= n; i++) {
      cin >> arr[j][i];
    }
  }
  solve();
}

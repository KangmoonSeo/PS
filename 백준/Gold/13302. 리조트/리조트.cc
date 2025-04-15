#include <bits/stdc++.h>
using namespace std;

#define MAX_COUPON 101
int n, m;
int not_visited[101];
int dp[101][MAX_COUPON];

/**
 * n: 수영이의 여름방학의 일수
 * m: 수영이가 리조트에 갈 수 없는 날의 수
 * not_visited: 수영이가 리조트에 갈 수 없는 날짜, arr번째
 *
 * @returns
 * (int): 주어진 입력에서 제시된 날을 제외한 나머지 날 모두
 *     리조트에 입장하기 위해서 지불해야 하는 비용의 최솟값
 */
int solve() {
  int input;
  for (int i = 0; i < m; i++) {
    cin >> input;
    not_visited[input] = true;
  }

  fill_n(dp[0], 101 * MAX_COUPON, 1e9);

  // i=0
  dp[0][0] = 0;

  // i>0
  for (int i = 1; i <= n; i++) {
    if (not_visited[i]) {
      for (int j = 0; j < MAX_COUPON; j++) {
        dp[i][j] = dp[i - 1][j];
      }
      //
    } else {
      // 하루 이용권 구매
      for (int j = 0; j < MAX_COUPON; j++) {
        dp[i][j] = min(dp[i][j], dp[i - 1][j] + 10000);
      }

      // 쿠폰 사용
      for (int j = 3; j < MAX_COUPON; j++) {
        if (dp[i - 1][j] < 1e9) {
          dp[i][j - 3] = min(dp[i][j - 3], dp[i - 1][j]);
        }
      }
    }

    // 연속 3일권 구매
    if (i >= 3) {
      for (int j = 1; j < MAX_COUPON; j++) {
        dp[i][j] = min(dp[i][j], dp[i - 3][j - 1] + 25000);
      }
    }

    // 연속 5일권 구매
    if (i >= 5) {
      for (int j = 2; j < MAX_COUPON; j++) {
        dp[i][j] = min(dp[i][j], dp[i - 5][j - 2] + 37000);
      }
    }
  }
  int ans = 1e9;

  for (int j = 0; j < MAX_COUPON; j++) {
    ans = min(ans, dp[n][j]);
  }
  if (ans > 1e8) return 0;
  return ans;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n >> m;
  auto ans = solve();
  cout << ans << "\n";
}

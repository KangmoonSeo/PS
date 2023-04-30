#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#define min(a, b) a < b ? a : b
using namespace std;

int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 실행속도 최적화 end
  int n;
  cin >> n;

  vector<vector<int> > dp(n + 1, vector<int>(3));

  cin >> dp[1][0] >> dp[1][1] >> dp[1][2];
  for (int i = 2; i <= n; i++) {
    cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
    dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]);
    dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]);
    dp[i][2] += min(dp[i - 1][0], dp[i - 1][1]);
  }

  int result = min(dp[n][0], dp[n][1]);
  result = min(result, dp[n][2]);
  cout << result << "\n";
}

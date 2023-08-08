#include <string>
#include <vector>

using namespace std;

int solution(int n) {
  long long MAX = 1'000'000'007;

  int answer = 0;
  long long dp[5001][7] = {};
  dp[2][0] = 1, dp[2][2] = 1, dp[2][6] = 3;

  for (int i = 3; i <= n; i++) {
    dp[i][0] = dp[i - 1][3];
    dp[i][1] = dp[i - 1][4];
    dp[i][2] = dp[i - 1][5];
    dp[i][3] = (dp[i - 1][6] + dp[i - 1][2]) % MAX;
    dp[i][4] = dp[i - 1][1];
    dp[i][5] = (dp[i - 1][6] + dp[i - 1][0]) % MAX;
    dp[i][6] = (dp[i - 2][6] + dp[i][0] + dp[i][2]) % MAX;
  }
  answer = dp[n][6];
  return answer;
}
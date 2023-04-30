#include <iostream>
#define min(a, b) a < b ? a : b
using namespace std;

int main() {
  int n, dp[1001][3] = {0};
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
    dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]);
    dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]);
    dp[i][2] += min(dp[i - 1][0], dp[i - 1][1]);
  }
  int result = min(dp[n][0], dp[n][1]);
  result = min(result, dp[n][2]);
  cout << result << "\n";
}

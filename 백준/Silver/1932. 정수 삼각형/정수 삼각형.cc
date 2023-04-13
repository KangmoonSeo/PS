#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define max(a, b) a > b ? a : b

using namespace std;

int dp[501][501] = {0};

void intRect(int n) {
  for (int i = 1; i < n; i++) {
    dp[i][0] += dp[i - 1][0];
    for (int j = 1; j <= i; j++) {
      dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
    }
  }

  int res = 0;
  for (int i = 0; i < n; i++) {
    res = max(res, dp[n - 1][i]);
  }

  cout << res << "\n";
}

int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 실행속도 최적화 end

  int n;  // input
  cin >> n;

  for (size_t i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      cin >> dp[i][j];
    }
  }
  intRect(n);
}

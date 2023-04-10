#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

unsigned long dp[101] = {
    0,
};

void padovan(int n) {
  dp[1] = 1, dp[2] = 1, dp[3] = 1, dp[4] = 2, dp[5] = 2, dp[6] = 3;
  int input;

  for (int i = 0; i < n; i++) {
    cin >> input;

    for (int j = 6; j <= input; j++) {
      if (dp[j] == 0) {
        dp[j] = dp[j - 1] + dp[j - 5];
      }
    }
    cout << dp[input] << "\n";
  }
}

int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 실행속도 최적화 end

  int n;  // input
  cin >> n;
  padovan(n);
}

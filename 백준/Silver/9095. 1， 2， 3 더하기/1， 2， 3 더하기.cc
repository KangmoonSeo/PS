#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int dp[11];

void func(int n) {
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;

  int input;
  for (int i = 0; i < n; i++) {
    cin >> input;

    for (int j = 4; j <= input; j++) {
      if (dp[j] == 0) dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
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
  func(n);
}

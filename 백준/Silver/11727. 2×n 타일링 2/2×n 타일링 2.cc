#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

unsigned int dp[1001];

void func(int n) {
  dp[0] = 1;
  dp[1] = 3;
  dp[2] = 5;

  for (int i = 3; i < n; i++) {
    dp[i] = dp[i - 2] * 3 + dp[i - 3] *2;
    dp[i] %= 10007;
  }
  cout << dp[n - 1];
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

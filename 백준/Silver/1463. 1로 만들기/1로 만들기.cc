#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 실행속도 최적화 end

  int n;  // input

  cin >> n;
  vector<int> dp(n + 1, 0);

  for (size_t i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + 1;
    if (!(i % 3)) dp[i] = min({dp[i], dp[i / 3] + 1});
    if (!(i % 2)) dp[i] = min({dp[i], dp[i / 2] + 1});
  }
  cout << dp[n];
}
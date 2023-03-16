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
  vector<int> dp(n + 1,
                 0);  // sol) 시간을 최소화하기 위한(O(n)) dynamic programming,
                      // bottom-up 방식으로 배열을 만들어 중복을 피한다.

  for (size_t i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + 1;
    if (!(i % 3)) dp[i] = min({dp[i], dp[i / 3] + 1});
    if (!(i % 2)) dp[i] = min({dp[i], dp[i / 2] + 1});
  }
  cout << dp[n];
}
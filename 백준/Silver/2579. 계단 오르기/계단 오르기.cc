#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define max(a, b) (a > b ? a : b)
using namespace std;

int dp[301][2] = {};  // dp[i][0] : tol:1, dp[i][1] : tol:2
int n;

int stair(vector<int>& arr) {
  if (n == 1)
    return arr[0];
  else if (n == 2)
    return arr[0] + arr[1];

  dp[0][0] = arr[0];
  dp[0][1] = 0;
  dp[1][0] = arr[1];
  dp[1][1] = arr[0] + arr[1];

  int tmp;
  for (int i = 2; i < n; i++) {
    tmp = arr[i];
    dp[i][0] = tmp + max(dp[i - 2][0], dp[i - 2][1]);
    dp[i][1] = tmp + dp[i - 1][0];
  }

  int res = max(dp[n - 1][0], dp[n - 1][1]);
  return res;
}

int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 실행속도 최적화 end

  // input
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << stair(arr);
}

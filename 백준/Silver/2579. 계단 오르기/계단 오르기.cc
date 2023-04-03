#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define max(a, b) (a > b ? a : b)
using namespace std;

int stair(vector<int>& arr) {
  int dp[301] = {};
  int len = arr.size();

  dp[0] = arr[0];
  if (len == 1) return dp[0];
  dp[1] = arr[0] + arr[1];
  if (len == 2) return dp[1];
  dp[2] = arr[2] + max(arr[0], arr[1]);
  if (len == 3) return dp[2];

  for (int i = 3; i < len; i++) {
    dp[i] =
        arr[i] + max(dp[i - 2],
                     arr[i - 1] + dp[i - 3]);  // max([0]+[-2], [0]+[-1]+[-3])
  }

  return dp[len - 1];
}

int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 실행속도 최적화 end

  int n;  // input
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << stair(arr);
}

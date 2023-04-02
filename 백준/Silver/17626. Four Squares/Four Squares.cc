#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int dp[2][50000] = {};

int sqrs(const int n) {
  const int idx = floor(sqrt(n));
  int tmp = 0;

  // res -> 1
  for (int i = 0; i < idx; i++) {
    tmp = (i + 1) * (i + 1);
    if (tmp == n) return 1;
    dp[0][i] = tmp;
  }
  // res -> 2
  int cnt_2 = 0;
  for (int i = 0; i < idx; i++) {
    for (int j = i; j < idx; j++) {
      tmp = dp[0][i] + dp[0][j];
      if (tmp == n) return 2;
      dp[1][cnt_2] = tmp;
      cnt_2++;
    }
  }
  // res -> 3
  for (int i = 0; i < cnt_2; i++) {
    for (int j = 0; j < idx; j++) {
      tmp = dp[1][i] + dp[0][j];
      if (tmp == n) return 3;
    }
  }
  // else -> 4
  return 4;
}

int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 실행속도 최적화 end

  int n;  // input
  cin >> n;
  int res = sqrs(n);
  cout << res;
}

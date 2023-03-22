#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int dp[5001] = {
    -1, -1, -1, 1, -1, 1,  // n=0, 1, 2, 3, 4, 5

};

int sugar(int n) {
  if (dp[n] != 0) return dp[n];
  if (n <= 5) return dp[n];
  int n3 = sugar(n - 3);
  int n5 = sugar(n - 5);

  if (n3 == -1 && n5 == -1) {
    dp[n] = -1;
  } else if (n3 != -1 && n5 == -1) {
    dp[n] = n3 + 1;
  } else if (n3 == -1 && n5 != -1) {
    dp[n] = n5 + 1;
  } else {
    dp[n] = min(n5, n3) + 1;
  }

  return dp[n];
}

int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 실행속도 최적화 end

  int n;  // input

  cin >> n;

  cout << sugar(n);
}

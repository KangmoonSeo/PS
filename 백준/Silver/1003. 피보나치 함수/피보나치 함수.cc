#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// 개선안 1. dp 함수를 0과 1 개별로 받지 않음
// 개선안 2. for문은 한 번만 사용함. 예외 처리 엄밀하게 준비

// dynamic programming, 실행 속도를 O(n)에 근접하게 맞추기 위함
int dp[50] = {
    0,
    1,
};

int fibo(int n) {
  if (n > 1 && dp[n] == 0) {
    dp[n] = fibo(n - 1) + fibo(n - 2);
  }
  return dp[n];
}
int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 실행속도 최적화 end

  int n;
  cin >> n;

  // input
  int input;

  for (size_t i = 0; i < n; i++) {
    cin >> input;
    // output
    if (input == 0) {
      cout << "1 0\n";
    } else {
      cout << fibo(input - 1) << " " << fibo(input) << "\n";
    }
  }
}
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void func(int n) {
  int ret = n / 5;
  for (int i = 1; i <= n; i++) {
    if (i % 25 == 0) ret++;
    if (i % 125 == 0) ret++;
  }

  cout << ret;
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

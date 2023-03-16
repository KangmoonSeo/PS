#include <algorithm>
#include <iostream>
using namespace std;

int func(int n, int tof) {  // 재귀를 이용한 방법, O(n^2) 예상
  int a = 100000, b = 100000, c = 100000;

  if (n == 1) return tof;

  if (n % 3 == 0) {
    a = func(n / 3, tof + 1);
  }
  if (n % 2 == 0) {
    b = func(n / 2, tof + 1);
  }
  c = func(n - 1, tof + 1);

  return min({a, b, c});
}

int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 실행속도 최적화 end

  int n;  // input
  cin >> n;

  cout << func(n, 0);  // output
}
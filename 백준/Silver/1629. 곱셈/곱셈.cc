#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

unsigned long long cross(unsigned long long a, unsigned long long b, unsigned long long c) {
  unsigned long long tmpA = a % c;
  bool isOdd = (b % 2 == 1);
  unsigned long long res;
  if (b == 1) {
    return tmpA;
  } else {
    res = cross(tmpA, b/2, c);
    if (isOdd) {
      return ((res * res) % c * tmpA) % c;
    } else {
      return (res * res) % c;
    }
  }
}

int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 실행속도 최적화 end

  unsigned long long a, b, c;  // input
  cin >> a >> b >> c;

  unsigned long long res = cross(a, b, c);
  cout << res << "\n";
}

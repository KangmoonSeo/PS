#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int cain(int const M, int const N, int const x, int const y) {
  int P, p, Q, q;
  int ret = -1;

  if (M > N) {
    P = M, p = x, Q = N, q = y;

  } else {
    P = N, p = y, Q = M, q = x;
  }
  if (P == p) {
    p = 0;
  }

  // (Q*i+q)%P == p
  for (int i = 0; i <= P; i++) {
    if ((Q * i + q) % P == p) {
      ret = Q * i + q;
      break;
    }
  }
  return ret;
}

int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 실행속도 최적화 end

  int n;  // input

  cin >> n;
  int M, N, x, y;

  for (int i = 0; i < n; i++) {
    cin >> M >> N >> x >> y;
    cout << cain(M, N, x, y) << "\n";
  }
}

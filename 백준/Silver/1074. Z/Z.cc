#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void funcZ(int n, int r, int c, int ret) {
  if (n == 0) {
    cout << ret << endl;
    return;
  }

  int n_div = pow(2, n - 1);  // 1->1, 2->2, 3->4, 4->8, 5->16, ...
  int n_ret = pow(4, n - 1);  // 1->1, 2->4, 3->16, 4->64, ...

  if (n_div >= r && n_div >= c) {  // 0 ~ 4^n/4 * 1
    funcZ(n - 1, r, c, ret);
  } else if (n_div >= r && n_div < c) {  // 4^n/4 * 1 ~ 4^n/4 * 2
    funcZ(n - 1, r, c - n_div, ret + n_ret);
  } else if (n_div < r && n_div >= c) {  // 4^n/4 * 2 ~ 4^n/4 * 3
    funcZ(n - 1, r - n_div, c, ret + n_ret * 2);
  } else if (n_div < r && n_div < c) {  // 4^n/4 * 3 ~ 4^n/4 * 4
    funcZ(n - 1, r - n_div, c - n_div, ret + n_ret * 3);
  }
}

int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 실행속도 최적화 end

  int n;  // input
  int r, c;
  cin >> n >> r >> c;

  funcZ(n, r + 1, c + 1, 0);
}

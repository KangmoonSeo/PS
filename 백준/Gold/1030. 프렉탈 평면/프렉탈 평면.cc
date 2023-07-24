#include <bits/stdc++.h>
using namespace std;

int s, n, k, r1, r2, c1, c2;

void recur(int x, int y, int num) {
  int len = (n - k) / 2;
  if ((x / num) % n >= len && (x / num) % n < n - len && (y / num) % n >= len &&
      (y / num) % n < n - len) {
    cout << "1";
  } else if (num / n == 0) {
    cout << "0";
  } else {
    recur(x, y, num / n);
  }
}
void solve() {
  int N = pow(n, s);
  for (int i = r1; i <= r2; i++) {
    for (int j = c1; j <= c2; j++) {
      recur(i, j, N);
    }
    cout << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> s;         // 시간 경과
  cin >> n;         // N*N 정사각형
  cin >> k;         // 가운데 K*K 검정 정사각형
  cin >> r1 >> r2;  // [r1, r2]
  cin >> c1 >> c2;  // [c1, c2]
  solve();
}

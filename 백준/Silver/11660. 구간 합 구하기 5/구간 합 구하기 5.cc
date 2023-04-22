#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int pSum[1025][1025] = {0};
int n, m;

void prefixSum() {
  int x1, y1, x2, y2;  // input
  cin >> y1 >> x1 >> y2 >> x2;
  int ans = 0;
  for (int j = y1; j <= y2; j++) {
    ans += pSum[x2][j] - pSum[x1 - 1][j];
  }
  cout << ans << "\n";
}

int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 실행속도 최적화 end

  cin >> n >> m;
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= n; i++) {
      cin >> pSum[i][j];
      pSum[i][j] += pSum[i - 1][j];
    }
  }

  for (int i = 0; i < m; i++) {
    prefixSum();
  }
}
  
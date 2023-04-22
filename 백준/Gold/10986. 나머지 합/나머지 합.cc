#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 실행속도 최적화 end

  int n, m, input;  // input
  cin >> n >> m;

  long long count[1001] = {0};
  long long mem = 0;

  for (int i = 0; i < n; i++) {  // prefix Sum
    cin >> input;
    mem += input;
    mem %= m;
    count[mem]++;
  }
  long long ans = 0;
  for (int i = 0; i < m; i++) {
    ans += count[i] * (count[i] - 1) / 2;  // count[i] Combination 2
  }

  cout << ans + count[0] << "\n";
}

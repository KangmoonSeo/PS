#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 실행속도 최적화 end

  int n;

  cin >> n;

  // input
  vector<int> input(n);
  int max = 0;
  for (size_t i = 0; i < n; i++) {
    cin >> input[i];
    max = max < input[i] ? input[i] : max;
  }
  // dynamic programming
  vector<int> dp_0(max + 1, 0);
  vector<int> dp_1(max + 1, 0);
  dp_0[0] = 1, dp_1[1] = 1;

  for (size_t i = 2; i <= max; i++) {
    dp_0[i] = dp_0[i - 1] + dp_0[i - 2];
    dp_1[i] = dp_1[i - 1] + dp_1[i - 2];
  }
  // output
  for (size_t i = 0; i < n; i++) {
    cout << dp_0[input[i]] << " " << dp_1[input[i]] << "\n";
  }
}
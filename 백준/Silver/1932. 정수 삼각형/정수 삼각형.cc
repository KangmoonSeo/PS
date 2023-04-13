#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define max(a, b) a > b ? a : b

using namespace std;

vector<vector<int> > dp(501, vector<int>(501));

void intRect(vector<vector<int> > const arr, int n) {
  dp[0][0] = arr[0][0];
  int tmp;
  for (int i = 1; i < n; i++) {
    dp[i][0] = arr[i][0] + dp[i - 1][0];
    for (int j = 1; j <= i; j++) {
      tmp = max(dp[i - 1][j - 1], dp[i - 1][j]);
      dp[i][j] = arr[i][j] + tmp;
    }
  }
   int res = *std::max_element(dp[n - 1].begin(), dp[n - 1].end());
   cout << res << "\n";
}

int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 실행속도 최적화 end

  int n;  // input
  cin >> n;
  vector<vector<int> > arr(501, vector<int>(501));

  for (size_t i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      cin >> arr[i][j];
    }
  }
  intRect(arr, n);
}

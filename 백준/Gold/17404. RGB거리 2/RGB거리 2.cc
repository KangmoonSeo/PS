#include <bits/stdc++.h>
using namespace std;

int n;
int weight[1001][3];
int dp[1001][3];

void solve() {
  int ans = 1e9;
  for (int init = 0; init < 3; init++) {
    for (int j = 0; j < 3; j++) {
      dp[1][j] = (j == init) ? weight[1][j] : 1e9;  // init으로 시작
    }
    for (int i = 2; i <= n; i++) {
      for (int j = 0; j < 3; j++) {
        int temp = 1e9;
        swap(temp, dp[i - 1][j]);
        dp[i][j] =
            weight[i][j] + min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
        swap(temp, dp[i - 1][j]);
      }
    }
    dp[n][init] = 1e9;  // init이 아닌 색으로 종료
    ans = min({ans, dp[n][0], dp[n][1], dp[n][2]});
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> weight[i][0] >> weight[i][1] >> weight[i][2];
  }
  solve();
}

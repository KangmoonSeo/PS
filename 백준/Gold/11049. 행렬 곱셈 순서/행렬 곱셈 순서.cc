#include <bits/stdc++.h>
using namespace std;

int n;
int d[501];
int dp[501][501] = {};

void solve() {
  dp[n][n] = 0;
  for (int l = 1; l < n; l++) {
    dp[l][l] = 0;
    for (int i = 1; i <= n - l; i++) {
      int j = i + l;
      for (int k = i; k < j; k++) {
        if (dp[i][j] == 0)
          dp[i][j] = dp[i][k] + dp[k + 1][j] + d[i - 1] * d[k] * d[j];
        else
          dp[i][j] =
              min(dp[i][j], dp[i][k] + dp[k + 1][j] + d[i - 1] * d[k] * d[j]);
      }
    }
  }
  cout << dp[1][n] << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> d[i] >> d[i + 1];
  }

  solve();
}

#include <bits/stdc++.h>
using namespace std;

int n, arr[10002], dp[10002] = {};

void solve() {
  for (int i = 1; i <= n + 1; i++) {
    // ~ 0
    dp[i] = dp[i - 1];

    // ~ 1 0
    if (i < 2) continue;
    dp[i] = max(dp[i], arr[i - 1] + dp[i - 2]);

    // ~ 1 1 0
    if (i < 3) continue;
    dp[i] = max(dp[i], arr[i - 1] + arr[i - 2] + dp[i - 3]);
  }
  cout << dp[n + 1] << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  solve();
}

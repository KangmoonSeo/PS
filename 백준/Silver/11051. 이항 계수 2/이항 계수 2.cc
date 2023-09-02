#include <bits/stdc++.h>
using namespace std;
#define MOD 10'007

int a, b, dp[1001][1001] = {};

int DP(int n, int k) {
  if (dp[n][k] > 0) return dp[n][k];
  if (k == 0 || k == n) {
    dp[n][k] = 1;
  } else {
    dp[n][k] = DP(n - 1, k - 1) + DP(n - 1, k);
    dp[n][k] %= MOD;
  }

  return dp[n][k];
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> a >> b;
  cout << DP(a, b) << "\n";
}

#include <bits/stdc++.h>
#define MOD 1000000000  // 1e9
using namespace std;

int n;

void solve() {
  unsigned int dp[101][10] = {};
  long long ans = 0;

  for (int j = 1; j <= n; j++) {
    for (int i = 0; i < 10; i++) {
      if (j < 2 && i > 0) dp[j][i] = 1;
      if (j > 1 && i - 1 >= 0) dp[j][i] += dp[j - 1][i - 1];
      if (j > 1 && i + 1 <= 9) dp[j][i] += dp[j - 1][i + 1];
      dp[j][i] %= MOD;
      if (j == n) ans = (ans % MOD + dp[j][i]) % MOD;
    }
  }
  cout << ans % MOD << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n;
  solve();
}

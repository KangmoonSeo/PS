#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
  int pSum[100001] = {};
  int dp[100001] = {};
  int min_val = 0;

  for (int i = 1; i <= n; i++) {
    cin >> pSum[i];
    pSum[i] += pSum[i - 1];
    if (min_val > pSum[i]) {
      dp[i] = max(dp[i - 1], pSum[i] - min_val);
      min_val = pSum[i];
    } else {
      dp[i] = max(dp[i - 1], pSum[i] - min_val);
    }
    if (i == 1) dp[i] = pSum[i];
  }
  cout << dp[n] << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n;
  solve();
}

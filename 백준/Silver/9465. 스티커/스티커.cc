#include <bits/stdc++.h>
#define max(a, b) a > b ? a : b
using namespace std;

void sticker() {
  int n;
  cin >> n;
  int arr[100001][2];
  int dp[100001][2];
  
  for (int i = 0; i < 2; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> arr[j][i];
    }
  }
  for (int j = 1; j <= n; j++) {
    for (int i = 0; i < 2; i++) {
      dp[j][i] = max(arr[j][i] + dp[j - 1][1 - i], dp[j - 1][i]);
    }
  }
  int ans = max(dp[n][0], dp[n][1]);
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  int T;  // input
  cin >> T;
  while (T--) {
    sticker();
  }
}

#include <bits/stdc++.h>
#define max(a, b) a > b ? a : b
using namespace std;

int arr[1001];
int dp[1001];

void solve(int n = 0) {
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    dp[i] = arr[i];
    for (int j = 1; j < i; j++) {
      if (arr[i] > arr[j]) {
        dp[i] = max(dp[i], dp[j] + arr[i]);
      }
    }
    ans = max(ans, dp[i]);
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  int n;  // input
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  solve(n);
}

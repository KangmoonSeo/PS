#include <bits/stdc++.h>
#define max(a, b) a > b ? a : b
using namespace std;

int n;
int arr[1001];
int dp[1001];

void solve() {
  int result = 0;
  for (int i = 1; i <= n; i++) {
    dp[i] = 1;
    for (int j = 1; j <= i; j++) {
      if (arr[i] > arr[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    result = max(result, dp[i]);
  }
  cout << result << "\n";
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  solve();
}

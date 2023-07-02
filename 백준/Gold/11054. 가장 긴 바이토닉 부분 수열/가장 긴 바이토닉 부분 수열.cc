#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1001];
int dp_u[1001] = {};
int dp_d[1001] = {};

void solve() {
  // function acts here
  //
  fill_n(dp_u, 1001, 1);
  fill_n(dp_d, 1001, 1);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      if (arr[i] > arr[j]) {
        dp_u[i] = max(dp_u[i], dp_u[j] + 1);
      }
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = n; j >= i; j--) {
      if (arr[i] > arr[j]) {
        dp_d[i] = max(dp_d[i], dp_d[j] + 1);
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, dp_u[i] + dp_d[i]);
  }
  cout << ans - 1 << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  solve();
}

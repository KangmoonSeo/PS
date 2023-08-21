#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
  long long ans = 0;
  int k = log10(n);
  for (int i = 1; i <= k; i++) {
    ans += i * 9 * pow(10, i - 1);
  }
  ans += (k + 1) * (n - pow(10, k) + 1);
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n;
  solve();
}

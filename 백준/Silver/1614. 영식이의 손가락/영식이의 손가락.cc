#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, m;

void solve() {
  ll ans = 0;
  if (n == 1) {
    ans = m * 8;
  } else if (n == 5) {
    ans = m * 8 + 4;
  } else {
    ans = (m + 1) / 2 * 8 + (m % 2 ? (1 - n) : (n - 1));
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n >> m;
  solve();
}

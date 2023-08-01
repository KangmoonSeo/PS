#include <bits/stdc++.h>
using namespace std;

int a, b;

void solve() {
  int ans = a * b;
  while (b > 0) {
    cout << a * (b % 10) << "\n";
    b /= 10;
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> a >> b;
  solve();
}

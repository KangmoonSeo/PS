#include <bits/stdc++.h>
using namespace std;

int x, y;

void solve() {
  int ans = 1;
  if (x > 0 && y > 0) ans = 1;
  if (x < 0 && y > 0) ans = 2;
  if (x < 0 && y < 0) ans = 3;
  if (x > 0 && y < 0) ans = 4;
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> x >> y;
  solve();
}

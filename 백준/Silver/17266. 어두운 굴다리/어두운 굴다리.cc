#include <bits/stdc++.h>
using namespace std;

int n, m;

void solve() {
  int input, mem = 0, ans = 0;
  for (int i = 0; i < m; i++) {
    cin >> input;
    int x = input - mem;
    if (i > 0) x = (x + 1) / 2;
    ans = max(x, ans);
    mem = input;
  }
  ans = max(n - mem, ans);
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n >> m;
  solve();
}

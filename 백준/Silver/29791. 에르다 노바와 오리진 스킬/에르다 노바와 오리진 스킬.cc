#include <bits/stdc++.h>
using namespace std;

int n, m, a[1000001], b[1000001];

void solve() {
  int ans[2] = {};

  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  sort(a, a + n);
  sort(b, b + m);

  int mem = -1e8;
  for (int i = 0; i < n; i++) {
    if (a[i] - mem >= 100) {
      mem = a[i];
      ans[0]++;
    }
  }

  mem = -1e8;
  for (int i = 0; i < m; i++) {
    if (b[i] - mem >= 360) {
      mem = b[i];
      ans[1]++;
    }
  }

  cout << ans[0] << " " << ans[1] << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n >> m;

  solve();
}

#include <bits/stdc++.h>
using namespace std;

int n, m, arr[101][101];

void solve() {
  int xy = 0, yz = 0, zx = 0;
  xy = 2 * n * m;
  int mem = 0;
  for (int j = 0; j < n; j++) {
    mem = 0;
    for (int i = 0; i < m; i++) {
      if (arr[j][i] > mem) yz += arr[j][i] - mem;
      mem = arr[j][i];
    }
    mem = 0;
    for (int i = m - 1; i >= 0; i--) {
      if (arr[j][i] > mem) yz += arr[j][i] - mem;
      mem = arr[j][i];
    }
  }
  for (int i = 0; i < m; i++) {
    mem = 0;
    for (int j = 0; j < n; j++) {
      if (arr[j][i] > mem) zx += arr[j][i] - mem;
      mem = arr[j][i];
    }
    mem = 0;
    for (int j = n - 1; j >= 0; j--) {
      if (arr[j][i] > mem) zx += arr[j][i] - mem;
      mem = arr[j][i];
    }
  }
  int ans = xy + yz + zx;
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n >> m;
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < m; i++) {
      cin >> arr[j][i];
    }
  }

  solve();
}

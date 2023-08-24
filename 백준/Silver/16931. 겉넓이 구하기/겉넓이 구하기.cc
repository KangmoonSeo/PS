#include <bits/stdc++.h>
using namespace std;

int n, m, arr[101][101];

void solve() {
  int xy = 0, yz = 0, zx = 0, mem, v;
  xy = 2 * n * m;
  for (int j = 0; j < n; j++) {
    mem = 0;
    for (int i = 0; i < m; i++) {
      v = arr[j][i];
      if (v > mem) yz += v - mem;
      mem = v;
    }
    mem = 0;
    for (int i = m - 1; i >= 0; i--) {
      v = arr[j][i];
      if (v > mem) yz += v - mem;
      mem = v;
    }
  }
  for (int i = 0; i < m; i++) {
    mem = 0;
    for (int j = 0; j < n; j++) {
      v = arr[j][i];
      if (v > mem) zx += v - mem;
      mem = v;
    }
    mem = 0;
    for (int j = n - 1; j >= 0; j--) {
      v = arr[j][i];
      if (v > mem) zx += v - mem;
      mem = v;
    }
  }
  cout << xy + yz + zx << "\n";
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

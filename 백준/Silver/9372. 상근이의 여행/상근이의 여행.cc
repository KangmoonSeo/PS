#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m, i1, i2;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> i1 >> i2;
  }
  cout << n - 1 << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}

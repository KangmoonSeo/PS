#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
  for (int i = 0; i < 9; i++) {
    cout << n << " * " << i + 1 << " = " << n * (i + 1) << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n;
  solve();
}

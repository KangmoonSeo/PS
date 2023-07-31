#include <bits/stdc++.h>
using namespace std;

int n, m, arr[500001], cmp;

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  cin >> m;
  while (m--) {
    cin >> cmp;
    int sz = upper_bound(arr, arr + n, cmp) - lower_bound(arr, arr + n, cmp);
    cout << sz << " ";
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  solve();
}

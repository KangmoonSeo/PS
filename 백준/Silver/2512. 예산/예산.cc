#include <bits/stdc++.h>
using namespace std;

int n, arr[10001], m;

bool condition(int v) {
  int ret = 0;
  for (int i = 0; i < n; i++) {
    ret += (arr[i] <= v) ? arr[i] : v;
    if (ret > m) return false;
  }
  return true;
}

void solve() {
  sort(arr, arr + n);
  int l = 0, r = arr[n - 1], ans = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (condition(mid)) {
      l = mid;
    } else {
      r = mid;
    }
    if (r - l <= 1) break;
  }
  if (condition(r))
    cout << r << "\n";
  else
    cout << l << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cin >> m;

  solve();
}

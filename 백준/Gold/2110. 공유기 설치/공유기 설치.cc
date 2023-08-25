#include <bits/stdc++.h>
using namespace std;

int n, c, arr[200001];

bool condition(int v) {
  int cnt = 1, mem = arr[0];
  for (int i = 1; i < n; i++) {
    int len = arr[i] - mem;
    if (len >= v) {  // 설치
      mem = arr[i];
      cnt++;
    }
  }
  if (cnt < c)
    return false;
  else
    return true;
}

void solve() {
  sort(arr, arr + n);
  int l = 0, r = arr[n - 1] - arr[0];
  while (l <= r) {
    int mid = (l + r) / 2;
    if (condition(mid)) {
      l = mid;
    } else {
      r = mid;
    }
    if (r - l <= 1) break;
  }
  cout << (condition(r) ? r : l) << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n >> c;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  solve();
}

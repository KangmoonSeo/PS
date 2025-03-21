#include <bits/stdc++.h>
using namespace std;

int n, c, arr[200001];

bool condition(int v) {
  int cnt = 1, mem = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] - mem >= v) {
      mem = arr[i];
      cnt++;
    }
  }
  return (cnt >= c);
}

int bsearch(int l, int r) {
  if (l > r) return r;
  int mid = (l + r) / 2;
  if (condition(mid)) {
    return bsearch(mid + 1, r);
  } else {
    return bsearch(l, mid - 1);
  }
}

void solve() {
  sort(arr, arr + n);
  cout << bsearch(0, arr[n - 1] - arr[0]) << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n >> c;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  solve();
}

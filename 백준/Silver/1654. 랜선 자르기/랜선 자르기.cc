#include <bits/stdc++.h>
using namespace std;

int k, n, arr[10001];

int calc(int sz) {
  int sum = 0;
  for (int i = 0; i < k; i++) {
    if (arr[i] < sz) continue;
    sum += arr[i] / sz;
  }
  return sum;
}
void solve() {
  sort(arr, arr + k);
  const int MAX_ARR = arr[k - 1];

  int sz = MAX_ARR;
  for (int len = MAX_ARR / 2; len >= 1; len /= 2) {
    int cnt = calc(sz);
    if (cnt >= n) {
      sz += len;
    } else {
      sz -= len;
    }
    if (sz == 0) sz++;
    if (len > 1 && len % 2) len++;
  }

  if (calc(sz) < n) {
    sz -= 1;
  }
  cout << sz << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> k >> n;
  for (size_t i = 0; i < k; i++) {
    cin >> arr[i];
  }
  solve();
}

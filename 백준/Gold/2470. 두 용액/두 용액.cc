#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100000];
int pos = -1;  // negative -> poisitive position

void solve() {
  sort(arr, arr + n);
  pos = upper_bound(arr, arr + n, 0) - arr;
  // monotonic case
  if (arr[n - 1] < 0) {  // monotonic negative
    cout << arr[n - 2] << " " << arr[n - 1] << "\n";
    return;
  } else if (arr[0] > 0) {  // monotonic positive
    cout << arr[0] << " " << arr[1] << "\n";
    return;
  }

  // bitonic case; two pointer
  int l = pos - 1, r = pos;
  int mem_l = l, mem_r = r, mem = abs(arr[mem_l] + arr[mem_r]);
  while (l > 0 || r < n - 1) {
    if (-arr[l] == arr[r]) {
      cout << arr[l] << " " << arr[r] << "\n";
      return;
    }
    (-arr[l] < arr[r]) ? l-- : r++;  // two pointer
    if (l < 0 || r > n - 1) break;
    if (mem > abs(arr[l] + arr[r])) {
      mem_l = l;
      mem_r = r;
      mem = abs(arr[mem_l] + arr[mem_r]);
    }
  }

  if (pos - 2 >= 0 && mem > abs(arr[pos - 2] + arr[pos - 1])) {
    mem_l = pos - 2;
    mem_r = pos - 1;
    mem = abs(arr[mem_l] + arr[mem_r]);
  }
  if (pos + 1 <= n - 1 && mem > abs(arr[pos] + arr[pos + 1])) {
    mem_l = pos;
    mem_r = pos + 1;
    mem = abs(arr[mem_l] + arr[mem_r]);
  }

  cout << arr[mem_l] << " " << arr[mem_r] << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  solve();
}

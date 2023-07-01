#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll arr[2001];

void solve() {
  if (n < 3) {
    cout << "0\n";
    return;
  }
  sort(arr, arr + n);

  int ans = 0;

  for (int i = 0; i < n; i++) {
    int l = 0, r = n - 1;
    while (l < r) {
      ll sum = arr[l] + arr[r];
      if (sum == arr[i]) {
        if (l == i) {
          l++;
        } else if (r == i) {
          r--;
        } else {
          ans++;
          break;
        }
      } else if (sum < arr[i]) {
        l++;
      } else {
        r--;
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  solve();
}

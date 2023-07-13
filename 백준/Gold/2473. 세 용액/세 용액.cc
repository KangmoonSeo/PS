#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int arr[5001];
void solve() {
  sort(arr, arr + n);
  int i, l, r;
  tuple<int, int, int> ans;
  ll mem = 200000000000LL;

  for (i = 0; i < n - 2; i++) {
    l = i + 1;
    r = n - 1;
    while (l < r) {
      ll sum = (ll)arr[i] + (ll)arr[l] + (ll)arr[r];
      if (mem > abs(sum)) {
        mem = abs(sum);
        ans = {i, l, r};
        if (sum == 0) l = n, i = n;  // break all
      } else if (sum < 0) {
        l++;
      } else {
        r--;
      }
    }
  }

  cout << arr[get<0>(ans)] << " " << arr[get<1>(ans)] << " " << arr[get<2>(ans)]
       << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  solve();
}

#include <bits/stdc++.h>
using namespace std;

int n, k, arr[10001];

void solve() {
  cin >> n >> k;
  vector<int> vec;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    if (vec.empty() || vec.back() < arr[i]) {
      vec.push_back(arr[i]);
    } else {
      int prev = lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin();
      vec[prev] = arr[i];
    }
  }
  int ans = vec.size() >= k ? 1 : 0;
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cout << "Case #" << i << "\n";
    solve();
  }
}

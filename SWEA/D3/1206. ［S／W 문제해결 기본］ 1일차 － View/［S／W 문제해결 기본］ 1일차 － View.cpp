#include <bits/stdc++.h>
using namespace std;

int n, arr[1001];

int find_local_maximum(int i) {
  int locals[5] = {arr[i - 2], arr[i - 1], arr[i], arr[i + 1], arr[i + 2]};
  int maxi = 0;
  for (auto loc : locals) {
    maxi = max(maxi, loc);
  }
  if (arr[i] < maxi) return 0;

  int ret = 1e8;
  locals[2] = 0;
  for (auto loc : locals) {
    ret = min(ret, maxi - loc);
  }
  return ret;
}

void solve() {
  int ans = 0;
  for (int i = 2; i < n - 2; i++) {
    ans += find_local_maximum(i);
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  for (int t = 1; t <= 10; t++) {
    cin >> n;

    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    cout << "#" << t << " ";
    solve();
  }
}

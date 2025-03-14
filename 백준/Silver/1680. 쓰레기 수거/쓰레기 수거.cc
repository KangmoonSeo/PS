#include <bits/stdc++.h>
using namespace std;

int _W, n;
/**
 *
 *
 */
void solve() {
  // function works here
  //
  int x, w;
  int current_w = 0;
  int ans = 0;

  // i in [1, n)
  for (int i = 1; i <= n - 1; i++) {
    cin >> x >> w;

    if (current_w + w == _W) {
      // 1. 쓰레기의 양이 용량에 도달했을 때 (exact one)
      ans += (x + x);
      current_w = 0;

    } else if (current_w + w > _W) {
      // 2. 그 지점의 쓰레기를 실었을 때 쓰레기차의 용량을 넘게 될 때.
      ans += (x + x);
      current_w = 0;
      current_w += w;
    } else {
      current_w += w;
    }
  }
  // i = n
  {
    cin >> x >> w;
    if (current_w + w <= _W) {
      // 3. 더 이상 쓰레기를 실을 지점이 없을 때.
      ans += (x + x);
      current_w = 0;
    } else {
      // 2. 그 지점의 쓰레기를 실었을 때 쓰레기차의 용량을 넘게 될 때.
      ans += x;
      // 3. 더 이상 쓰레기를 실을 지점이 없을 때.
      ans += (x + x + x);
      current_w = 0;
    }
  }

  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    cin >> _W >> n;
    solve();
  }
}

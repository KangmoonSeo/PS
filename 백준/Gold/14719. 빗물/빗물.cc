#include <bits/stdc++.h>
using namespace std;

int h, w;
int arr[502] = {};
int space[502][502] = {};

void shrink(int j) {
  int l = 1, r = w;
  bool stop_l = false, stop_r = false;
  while (l <= r) {
    if (space[j][l] == 1) stop_l = true;
    if (space[j][r] == 1) stop_r = true;
    if (stop_l && stop_r) break;
    if (!stop_l) {
      if (space[j][l - 1] == 0) {
        space[j][l] = 0;
      }
      l++;
    }
    if (!stop_r) {
      if (space[j][r + 1] == 0) {
        space[j][r] = 0;
      }
      r--;
    }
  }
}
void build() {
  for (int j = 0; j <= h; j++) {
    for (int i = 1; i <= w; i++) {
      if (j > arr[i])
        space[j][i] = 9;  // rain
      else
        space[j][i] = 1;  // structure
    }
  }
}
int count() {
  int ret = 0;
  for (int j = h; j >= 0; j--) {
    for (int i = 1; i <= w; i++) {
      if (space[j][i] == 9) ret++;
    }
  }
  return ret;
}
void solve() {
  /**
   * 0: void
   * 1: structure
   * 9: rain
   */
  build();
  for (int j = h; j >= 1; j--) shrink(j);

  int ans = count();
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> h >> w;
  for (int i = 1; i <= w; i++) {
    cin >> arr[i];
  }

  solve();
}

#include <bits/stdc++.h>
using namespace std;

int x_1, x_2, y_1, y_2;
int n;
/**
 * 원 안에 점이 있는지 판별
 * 있으면 +1, 없으면 0
 *   p1 p2
 *   x  x  x
 *   o  x  o
 *   x  o  o
 *   o  o  x
 */
bool is_in_circle(int c_x, int c_y, int r, int x, int y) {
  //
  long long d_x = c_x - x;
  long long d_y = c_y - y;
  if (d_x * d_x + d_y * d_y < r * r) {
    return true;
  } else {
    return false;
  }
}

int solve() {
  // function works here
  int c_x, c_y, r;

  int ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> c_x >> c_y >> r;

    bool src_in = is_in_circle(c_x, c_y, r, x_1, y_1);
    bool dst_in = is_in_circle(c_x, c_y, r, x_2, y_2);
    if (src_in ^ dst_in) ans++;
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    cin >> x_1 >> y_1 >> x_2 >> y_2;
    cin >> n;
    auto ans = solve();

    cout << ans << "\n";
  }
}

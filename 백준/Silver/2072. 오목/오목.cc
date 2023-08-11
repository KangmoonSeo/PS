#include <bits/stdc++.h>
using namespace std;
const int dy[4] = {1, 1, 1, 0};
const int dx[4] = {-1, 0, 1, -1};

int n, arr[102][102];

bool check(int y, int x, int color) {
  for (int i = 0; i < 4; i++) {
    int seq = 0;
    for (int j = n * -1; j <= n; j++) {
      int ny = y + j * dy[i];
      int nx = x + j * dx[i];
      if (nx < 0 || nx > n || ny < 0 || ny > n || arr[ny][nx] != color) {
        if (seq == 5) return true;
        seq = 0;
      } else {
        seq++;
      }
    }
    if (seq == 5) return true;
  }
  return false;
}
void solve() {
  fill_n(arr[0], 102 * 102, -1);

  int i, x, y, ans = -1;

  for (i = 1; i <= n; i++) {
    cin >> x >> y;
    arr[y][x] = (i % 2);  // 1:b, 0:w
    if (ans < 0 && check(y, x, i % 2)) ans = i;
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n;
  solve();
}

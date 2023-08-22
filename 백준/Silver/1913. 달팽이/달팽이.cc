#include <bits/stdc++.h>
using namespace std;
#define y first
#define x second
typedef pair<int, int> pii;
enum DIR {
  UP,
  LEFT,
  DOWN,
  RIGHT,
} dir;
const int dy[4] = {-1, 0, 1, 0};  // U, R, D, L
const int dx[4] = {0, 1, 0, -1};

int n, m, arr[1001][1001] = {};

bool canGo(pii p) {
  pii np = {p.y + dy[dir], p.x + dx[dir]};
  return (np.y >= 0 && np.x >= 0 && np.y < n && np.x < n);
}

void solve() {
  int cnt = 0;
  dir = UP;
  pii p = {n / 2, n / 2};
  arr[p.y][p.x] = ++cnt;  // 1
  p = {p.y + dy[dir], p.x + dx[dir]};
  arr[p.y][p.x] = ++cnt;  // 2

  do {
    DIR nxt = static_cast<DIR>((dir + 1) % 4);
    pii np = {p.y + dy[nxt], p.x + dx[nxt]};
    if (arr[np.y][np.x] == 0) dir = nxt;

    p = {p.y + dy[dir], p.x + dx[dir]};  // move
    if (!canGo(p)) break;
    arr[p.y][p.x] = ++cnt;
  } while (cnt < n * n);

  pii mem = {-1, -1};
  n -= 2;
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= n; i++) {
      cout << arr[j][i] << " ";
      if (arr[j][i] == m) mem = {j, i};
    }
    cout << "\n";
  }
  cout << mem.y << " " << mem.x << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n >> m;
  n += 2;

  solve();
}

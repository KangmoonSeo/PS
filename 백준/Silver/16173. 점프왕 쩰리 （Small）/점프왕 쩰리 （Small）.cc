#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define y first
#define x second

const int dy[2] = {1, 0};
const int dx[2] = {0, 1};

int n, arr[5][5] = {}, visited[5][5] = {};

void solve() {
  queue<pii> q;
  q.push({1, 1});
  visited[1][1] = true;
  bool ans = false;
  while (!q.empty()) {
    pii p = q.front();
    q.pop();
    int w = arr[p.y][p.x];
    if (p.y == n && p.x == n) {
      ans = true;
      break;
    }
    for (int i = 0; i < 2; i++) {
      int ny = p.y + w * dy[i];
      int nx = p.x + w * dx[i];

      if (ny < 1 || ny > n || nx < 1 || nx > n || visited[ny][nx]) continue;
      q.push({ny, nx});
      visited[ny][nx] = true;
    }
  }

  cout << (ans ? "HaruHaru\n" : "Hing\n");
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n;
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= n; i++) {
      cin >> arr[j][i];
    }
  }

  solve();
}

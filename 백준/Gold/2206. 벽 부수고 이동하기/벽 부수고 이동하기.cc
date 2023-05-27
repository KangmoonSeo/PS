#include <bits/stdc++.h>
using namespace std;
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};
struct User {
  int _cnt, _z, _y, _x;
};
int n, m;
int arr[1002][1002] = {};
bool visited[2][1002][1002] = {};

void solve() {
  queue<User> q;
  struct User init = {1, 0, 1, 1};  // cnt=1, (x,y,z)=(1,1,0)
  q.push(init);
  visited[0][1][1] = true;  // 벽을 한 번 지나면 z++, z>=2면  out
  int ans = -1;
  while (!q.empty()) {
    int cnt = q.front()._cnt;  // 지속시간
    int z = q.front()._z;
    int y = q.front()._y;
    int x = q.front()._x;
    q.pop();

    if (y == n && x == m) {  // 목적지 도착 시 break
      ans = cnt;
      break;
    }

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      int nz = z + arr[ny][nx];  // 수명이 정해진 BFS
      if (nz > 1) continue;

      if (!visited[nz][ny][nx]) {
        visited[nz][ny][nx] = true;
        struct User nxt = {cnt + 1, nz, ny, nx};
        q.push(nxt);
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n >> m;
  fill_n(arr[0], 1002 * 1002, 2);  // 외벽은 2칸짜리 벽
  string str;
  for (int j = 1; j <= n; j++) {
    cin >> str;
    for (int i = 1; i <= m; i++) {
      arr[j][i] = str[i - 1] - '0';
    }
  }
  solve();
}

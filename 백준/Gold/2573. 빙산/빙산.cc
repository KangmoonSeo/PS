#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define y first
#define x second
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int n, m;
int arr[302][302];
pii start = {0, 0};
bool shrink() {
  bool visited[302][302] = {};
  queue<pii> q;
  q.push(start);
  visited[start.y][start.x] = true;
  start = {0, 0};
  while (!q.empty()) {
    pii p = q.front();
    q.pop();
    int damage = 0;
    for (int i = 0; i < 4; i++) {
      int ny = dy[i] + p.y;
      int nx = dx[i] + p.x;
      if (arr[ny][nx] == 0 && !visited[ny][nx]) {
        damage++;
      } else if (arr[ny][nx] > 0 && !visited[ny][nx]) {
        visited[ny][nx] = true;
        q.push({ny, nx});
      }
    }
    arr[p.y][p.x] -= damage;
    if (arr[p.y][p.x] > 0) {
      start = {p.y, p.x};
    } else {
      arr[p.y][p.x] = 0;
    }
  }
  if (start.y == 0)
    return false;
  else
    return true;
}
int checkDist() {
  bool isEmpty = true;
  bool flag = false;
  bool visited[302][302] = {};

  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= m; i++) {
      if (arr[j][i] > 0 && !visited[j][i]) {
        isEmpty = false;
        if (flag) return 1;  // dist
        flag = true;
        // bfs start
        queue<pii> q;
        visited[j][i] = true;
        q.push({j, i});
        while (!q.empty()) {
          pii p = q.front();
          q.pop();
          for (int k = 0; k < 4; k++) {
            int ny = dy[k] + p.y;
            int nx = dx[k] + p.x;
            if (arr[ny][nx] > 0 && !visited[ny][nx]) {
              visited[ny][nx] = true;
              q.push({ny, nx});
            }
          }
        }
        // bfs end
      }
    }
  }
  if (isEmpty)
    return 0;  // empty
  else
    return -1;  // continue
}

void solve() {
  int T = 0;
  while (++T) {
    shrink();
    int end = checkDist();  // returns -1: continue, 0:empty, 1: distinct

    if (end == 1) {
      break;
    } else if (end == 0) {
      T = 0;
      break;
    }
  }
  cout << T << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  fill_n(arr[0], 302 * 302, -1);
  cin >> n >> m;
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= m; i++) {
      cin >> arr[j][i];
      if (arr[j][i] > 0 && start.y == 0) start = {j, i};
    }
  }
  solve();
}

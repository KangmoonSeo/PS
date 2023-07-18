#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define y first
#define x second
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int n, m, arr[302][302];
pii start = {0, 0};
void shrink() {
  bool visited[302][302] = {};
  queue<pii> q;
  q.push(start);
  visited[start.y][start.x] = true;
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
}
int checkDist() {
  bool isEmpty = true, isDist = false, visited[302][302] = {};

  for (int j = 2; j < n; j++) {
    for (int i = 2; i < m; i++) {
      if (arr[j][i] > 0 && !visited[j][i]) {
        isEmpty = false;
        if (isDist) return 1;  // dist
        isDist = true;
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
  return isEmpty ? 0 : -1;  // empty or not
}

void solve() {
  int T = 0;
  while (++T) {
    shrink();
    int isDist = checkDist();  // 0:empty, 1: dist
    if (isDist == 1) {
      cout << T << "\n";
      return;
    } else if (isDist == 0) {
      cout << "0\n";
      break;
    }
  }
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

#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// {x,y|x in [0,49], y in [0,49]}; 0: none, 1: marked, 2:visited
vector<vector<int> > place(50, vector<int>(50));  // adj array
int m, n;

bool isBoundary(int tx, int ty) {
  bool ret = tx >= 0 && tx < m && ty >= 0 && ty < n;
  if (!ret) return false;       // integrity check
  return (place[tx][ty] == 1);  // none / visit check
}

int search(int x, int y) {
  if (place[x][y] != 1) return 0;  // marked check
  place[x][y] = 2;                 // visited

  // bfs start
  queue<pair<int, int> > q;
  q.push(make_pair(x, y));
  while (!q.empty()) {
    int tx = q.front().first;
    int ty = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      if (isBoundary(tx + dx[i], ty + dy[i])) {
        place[tx + dx[i]][ty + dy[i]] = 2;  // visit
        q.push(make_pair(tx + dx[i], ty + dy[i]));
      }
    }
  }
  // bfs end
  return 1;
}

void cabbage() {
  int k, x, y;
  cin >> m >> n >> k;

  place.clear();
  place.assign(m, vector<int>(n));

  for (int i = 0; i < k; i++) {  // input pair
    cin >> x >> y;
    place[x][y] = 1;
  }

  int cnt = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cnt += search(i, j);
    }
  }
  cout << cnt << "\n";
}

int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 실행속도 최적화 end

  int T;  // input
  cin >> T;
  while (T--) {
    cabbage();
  }
}

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {-1, 0, 1, 0};

int n, m, arr[2002][2002];
bool ans[2002][2002] = {};
bool visited[2002][2002][4] = {};
vector<pii> vec;

/**
 * [dir]
 * 0: <-, 1: v, 2: ->, 3: ^
 *
 * [place]
 * 1: |   :: 0,2 -> x, 1,3 -> 1,3
 * 2: --  :: 1,3 -> x, 0,2 -> 0,2
 * 3: /   :: 0 <-> 1 // 2 <-> 3
 * 4: \   :: 0 <-> 3 // 1 <-> 2
 **/
int getNext(int place, int cur) {
  switch (place) {
    case 0:
    case 9:
      return cur;
    case 1:
      return (cur % 2 == 0) ? -1 : cur;
    case 2:
      return (cur % 2 == 1) ? -1 : cur;
    case 3:
      return (5 - cur) % 4;
    case 4:
      return (7 - cur) % 4;
  }
  return -1;
}

void bfs(pii init) {
  ans[init.first][init.second] = true;

  queue<pair<pii, int>> q;
  for (int i = 0; i < 4; i++) {
    if (arr[init.first][init.second] < 0) continue;
    q.push({{init.first, init.second}, i});
  }

  while (!q.empty()) {
    pair<pii, int> qq = q.front();
    pii p = q.front().first;
    int dir = q.front().second;
    ans[p.first][p.second] = true;
    q.pop();

    int nxt = getNext(arr[p.first][p.second], dir);
    if (nxt < 0) continue;

    int ny = dy[nxt] + p.first;
    int nx = dx[nxt] + p.second;
    if (arr[ny][nx] < 0) continue;
    if (visited[ny][nx][nxt]) continue;
    visited[ny][nx][nxt] = true;
    q.push({{ny, nx}, nxt});
  }
}
void solve() {
  for (pii p : vec) {
    bfs(p);
  }

  int cnt = 0;
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= m; i++) {
      if (ans[j][i]) cnt++;
    }
  }
  cout << cnt << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  fill_n(arr[0], 2002 * 2002, -1);

  cin >> n >> m;

  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= m; i++) {
      cin >> arr[j][i];
      if (arr[j][i] == 9) vec.push_back({j, i});
    }
  }

  solve();
}

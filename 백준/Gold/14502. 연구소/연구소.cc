#include <bits/stdc++.h>
using namespace std;
#define y first
#define x second
#define WALL 1
typedef pair<int, int> pii;
const int dy[4] = {1, 0, -1, 0};
const int dx[4] = {0, 1, 0, -1};

int n, m;
vector<pii> zeros;
queue<pii> contams;
vector<vector<int> > arr(10, vector<int>(10, WALL));  // initial input
vector<vector<int> > sp;                              // space for simulation

void simulate() {
  queue<pii> q = contams;
  while (!q.empty()) {
    pii p = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int ny = p.y + dy[i];
      int nx = p.x + dx[i];
      if (sp[ny][nx] == 0) {  // no 'visited' array
        sp[ny][nx] = 2;
        q.push({ny, nx});
      }
    }
  }
}
int countZero() {
  int ret = 0;
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= m; i++) {
      if (sp[j][i] == 0) ret++;
    }
  }
  return ret;
}
void solve() {
  int ans = 0;
  int length = zeros.size();
  for (int i = 0; i < length; i++) {
    for (int j = i + 1; j < length; j++) {
      for (int k = j + 1; k < length; k++) {
        sp = arr;
        sp[zeros[i].y][zeros[i].x] = WALL;
        sp[zeros[j].y][zeros[j].x] = WALL;
        sp[zeros[k].y][zeros[k].x] = WALL;
        simulate();
        ans = max(ans, countZero());
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n >> m;
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= m; i++) {
      cin >> arr[j][i];
      if (arr[j][i] == 0) zeros.push_back({j, i});  // for brute force
      if (arr[j][i] == 2) contams.push({j, i});     // for bfs
    }
  }
  solve();
}

/*
 * 23.06.23. 16:52 start
 * 23.06.23. 17:29 end
 */
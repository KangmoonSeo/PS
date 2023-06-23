#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int dy[4] = {1, 0, -1, 0};
const int dx[4] = {0, 1, 0, -1};

int n, m;
queue<pii> contamPoint;
vector<pii> zeroPoint;
vector<vector<int> > arr(10, vector<int>(10, 1));  // initial space
vector<vector<int> > space;

void simulate() {
  queue<pii> q = contamPoint;
  while (!q.empty()) {
    pii p = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int ny = p.first + dy[i];
      int nx = p.second + dx[i];
      if (space[ny][nx] == 0) {
        space[ny][nx] = 2;
        q.push({ny, nx});
      }
    }
  }
}
int countZero() {
  int ret = 0;
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= m; i++) {
      if (space[j][i] == 0) ret++;
    }
  }
  return ret;
}
void solve() {
  int ans = 0;
  int length = zeroPoint.size();
  for (int i = 0; i < length; i++) {
    for (int j = i + 1; j < length; j++) {
      for (int k = j + 1; k < length; k++) {
        space = arr;
        space[zeroPoint[i].first][zeroPoint[i].second] = 1;
        space[zeroPoint[j].first][zeroPoint[j].second] = 1;
        space[zeroPoint[k].first][zeroPoint[k].second] = 1;
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
      if (arr[j][i] == 0) zeroPoint.push_back({j, i});
      if (arr[j][i] == 2) contamPoint.push({j, i});
    }
  }
  solve();
}

/*
 * 23.06.23. 16:52 start
 * 23.06.23. 17:20 end
 */
#include <bits/stdc++.h>
using namespace std;
typedef pair<pair<int, int>, int> ppii;
struct cmp {
  bool operator()(ppii a, ppii b) {
    if (a.second == b.second) {
      if (a.first.first == b.first.first)
        return a.first.second > b.first.second;
      else
        return a.first.first > b.first.first;
    } else
      return a.second > b.second;
  }
};
const int dy[4] = {-1, 0, 0, 1};
const int dx[4] = {0, -1, 1, 0};

int n;
vector<vector<int> > arr(22, vector<int>(22, 1e9));
priority_queue<ppii, vector<ppii>, cmp> q;
bool visited[22][22] = {};

void solve() {
  int ans = 0;
  int level = 2;
  int exp = 0;

  while (!q.empty()) {
    int y = q.top().first.first;
    int x = q.top().first.second;
    int cnt = q.top().second;
    q.pop();

    // current site is eatables
    if (arr[y][x] > 0 && arr[y][x] < level) {
      // clear data
      q = priority_queue<ppii, vector<ppii>, cmp>();
      fill_n(visited[0], 22 * 22, false);
      // eat
      arr[y][x] = 0;
      ans += cnt;
      exp++;
      if (exp == level) {
        level++;
        exp = 0;
      }
      // restart
      q.push(make_pair(make_pair(y, x), 0));
      visited[y][x] = true;
      continue;
    }

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (visited[ny][nx]) continue;      // it's visited
      if (arr[ny][nx] > level) continue;  // can't move
      // else, move
      q.push(make_pair(make_pair(ny, nx), cnt + 1));
      visited[ny][nx] = true;
    }
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n;
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= n; i++) {
      cin >> arr[j][i];
      if (arr[j][i] == 9) {
        q.push(make_pair(make_pair(j, i), 0));
        visited[j][i] = true;
        arr[j][i] = 0;
      }
    }
  }

  solve();
}

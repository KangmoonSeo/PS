#include <bits/stdc++.h>
using namespace std;
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {-1, 0, 1, 0};

int n, m;
int arr[104][104] = {};
int h[104][104] = {};
bool visited[104][104] = {};

bool remove() {
  bool ret = false;
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= m; i++) {
      if (h[j][i] > 1) {
        arr[j][i] = 0;
        ret = true;
      }
    }
  }
  return ret;
}
void heat() {
  fill_n(visited[0], 104 * 104, false);
  fill_n(h[0], 104 * 104, 0);

  queue<pair<int, int> > q;
  q.push(make_pair(0, 0));
  visited[0][0] = true;
  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int ny = p.first + dy[i];
      int nx = p.second + dx[i];
      if (ny > n || ny < 0 || nx > m || nx < 0) continue;
      if (arr[ny][nx] == 0 && !visited[ny][nx]) {
        visited[ny][nx] = true;
        q.push(make_pair(ny, nx));
      }
      if (arr[ny][nx] == 1) {
        h[ny][nx]++;
      }
    }
  }
}
void solve() {
  int ans = 0;
  bool fl = true;
  while (fl) {
    heat();
    fl = remove();
    if (fl) ans++;
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n >> m;
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= m; i++) {
      cin >> arr[j][i];
    }
  }
  solve();
}

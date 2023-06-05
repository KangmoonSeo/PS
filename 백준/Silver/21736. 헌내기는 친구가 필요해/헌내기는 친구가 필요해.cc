#include <bits/stdc++.h>
#define y first
#define x second
using namespace std;
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int n, m;
pair<int, int> init;
char arr[602][602];
bool visited[602][602] = {};

void solve() {
  queue<pair<int, int> > q;
  q.push(init);
  visited[init.y][init.x] = true;
  int ans = 0;
  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int ny = p.y + dy[i];
      int nx = p.x + dx[i];
      if (!visited[ny][nx] && arr[ny][nx] != 'X') {
        visited[ny][nx] = true;
        if (arr[ny][nx] == 'P') ans++;
        q.push(make_pair(ny, nx));
      }
    }
  }
  if (ans == 0)
    cout << "TT\n";
  else
    cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization
  fill_n(arr[0], 602 * 602, 'X');

  cin >> n >> m;
  string str;
  for (int j = 1; j <= n; j++) {
    cin >> str;
    for (int i = 1; i <= m; i++) {
      arr[j][i] = str[i - 1];
      if (arr[j][i] == 'I') init = make_pair(j, i);
    }
  }
  solve();
}

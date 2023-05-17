#include <bits/stdc++.h>
using namespace std;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};
int n;
vector<vector<char> > arr(102, vector<char>(102, 'x'));
bool visited[101][101] = {};

void dfs(int y, int x, char initColor) {
  for (int d = 0; d < 4; d++) {
    int ny = y + dy[d];
    int nx = x + dx[d];
    if (!visited[ny][nx] && arr[ny][nx] == initColor) {
      visited[ny][nx] = true;
      dfs(ny, nx, initColor);
    }
  }
}

void solve() {
  string input;
  for (int j = 1; j <= n; j++) {
    cin >> input;
    for (int i = 0; i < n; i++) {
      arr[j][i + 1] = input[i];
    }
  }
  // 일반
  int cnt = 0;
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= n; i++) {
      if (!visited[j][i]) {
        visited[j][i] = true;
        dfs(j, i, arr[j][i]);
        cnt++;
      }
    }
  }
  cout << cnt << " ";
  // trans
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= n; i++) {
      if (arr[j][i] == 'G') arr[j][i] = 'R';
    }
  }
  // 적록
  fill_n(visited[0], 101 * 101, false);
  cnt = 0;
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= n; i++) {
      if (!visited[j][i]) {
        visited[j][i] = true;
        dfs(j, i, arr[j][i]);
        cnt++;
      }
    }
  }
  cout << cnt << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n;
  solve();
}

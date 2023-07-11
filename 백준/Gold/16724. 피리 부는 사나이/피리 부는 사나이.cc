#include <bits/stdc++.h>
using namespace std;

int n, m, key = 0, visited[1000][1000] = {};
char arr[1000][1000] = {};

bool dfs(int y, int x) {
  int ny = y;
  int nx = x;

  if (arr[y][x] == 'U') {
    ny--;
  } else if (arr[y][x] == 'D') {
    ny++;
  } else if (arr[y][x] == 'L') {
    nx--;
  } else {
    nx++;
  }

  if (visited[ny][nx] == 0) {
    visited[ny][nx] = key;
    return dfs(ny, nx);
  } else if (visited[ny][nx] == key) {
    return true;
  } else {
    return false;
  }
}

void solve() {
  int ans = 0;
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < m; i++) {
      if (visited[j][i] == 0) {
        key++;
        visited[j][i] = key;
        if (dfs(j, i)) ans++;
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n >> m;
  string input;
  for (int j = 0; j < n; j++) {
    cin >> input;
    for (int i = 0; i < m; i++) {
      arr[j][i] = input[i];
    }
  }
  solve();
}

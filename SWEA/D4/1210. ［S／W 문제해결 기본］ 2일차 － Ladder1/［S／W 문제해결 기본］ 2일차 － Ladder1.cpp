#include <bits/stdc++.h>
using namespace std;

int arr[102][102] = {};

int solve() {
  // function works here
  //
  bool visited[102][102];
  fill_n(visited[0], 102 * 102, false);

  int y = 100;
  int x = 0;

  for (int j = 1; j <= 100; j++) {
    for (int i = 1; i <= 100; i++) {
      cin >> arr[j][i];
      if (arr[j][i] == 2) x = i;
    }
  }

  while (y > 1) {
    // right
    int ny = y;
    int nx = x + 1;
    if (!visited[ny][nx] && arr[ny][nx] > 0) {
      visited[ny][nx] = true;
      y = ny, x = nx;
      continue;
    }

    // left
    ny = y;
    nx = x - 1;
    if (!visited[ny][nx] && arr[ny][nx] > 0) {
      visited[ny][nx] = true;
      y = ny, x = nx;

      continue;
    }

    // up
    ny = y - 1;
    nx = x;
    if (!visited[ny][nx] && arr[ny][nx] > 0) {
      visited[ny][nx] = true;
      y = ny, x = nx;
      continue;
    }
  }

  return x - 1;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  for (int i = 1; i <= 10; i++) {
    int T;
    cin >> T;
    int ans = solve();
    cout << "#" << i << " " << ans << "\n";
  }
}

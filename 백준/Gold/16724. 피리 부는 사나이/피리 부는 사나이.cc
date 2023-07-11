#include <bits/stdc++.h>
using namespace std;
#define y first
#define x second
typedef pair<int, int> pii;
int n, m;
char arr[1002][1002] = {};
int visited[1002][1002] = {};

int cnt = 0;

bool dfs(pii p) {
  pii np;
  if (arr[p.y][p.x] == 'U') {
    np = {p.y - 1, p.x};
  } else if (arr[p.y][p.x] == 'D') {
    np = {p.y + 1, p.x};
  } else if (arr[p.y][p.x] == 'L') {
    np = {p.y, p.x - 1};
  } else {
    np = {p.y, p.x + 1};
  }
  if (visited[np.y][np.x] == 0) {
    visited[np.y][np.x] = cnt;
    return dfs(np);
  } else if (visited[np.y][np.x] == cnt) {
    return true;
  } else {
    return false;
  }
}

void solve() {
  int ans = 0;
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= m; i++) {
      if (visited[j][i] == 0) {
        cnt++;
        visited[j][i] = cnt;
        if (dfs({j, i})) ans++;
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n >> m;
  string input;
  for (int j = 1; j <= n; j++) {
    cin >> input;
    for (int i = 1; i <= m; i++) {
      arr[j][i] = input[i - 1];
    }
  }
  solve();
}

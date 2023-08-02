#include <bits/stdc++.h>
using namespace std;
const int dy[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int r, s;
int arr[52][52] = {};
bool adj[2500][2500] = {};

int seat(int y, int x) { return y * 50 + x; }

void solve() {
  // 1. find new seat
  int ans = 0;
  for (int j = 1; j <= r; j++) {
    for (int i = 1; i <= s; i++) {
      if (arr[j][i] == 0) {
        int cnt = 0;
        for (int k = 0; k < 8; k++) {
          int ny = dy[k] + j;
          int nx = dx[k] + i;
          if (arr[ny][nx] > 0) cnt++;
        }
        ans = max(ans, cnt);
      }
    }
  }
  // 2. calculate connections
  for (int j = 1; j <= r; j++) {
    for (int i = 1; i <= s; i++) {
      if (arr[j][i] <= 0) continue;
      for (int k = 0; k < 8; k++) {
        int ny = dy[k] + j;
        int nx = dx[k] + i;
        if (arr[ny][nx] <= 0) continue;
        int u = seat(j, i);
        int v = seat(ny, nx);
        if (u < v) swap(u, v);
        if (!adj[u][v]) ans++;
        adj[u][v] = true;
      }
    }
  }

  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  fill_n(arr[0], 52 * 52, -1);  // wall
  cin >> r >> s;
  string str;
  for (int j = 1; j <= r; j++) {
    cin >> str;
    for (int i = 1; i <= s; i++) {
      arr[j][i] = (str[i - 1] == '.') ? 0 : 1;
    }
  }

  solve();
}

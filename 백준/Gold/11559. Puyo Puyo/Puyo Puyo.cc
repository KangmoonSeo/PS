#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};
const int H = 12, W = 6;

char arr[14][8];
int ans = 0;

bool bfs(int y, int x) {
  bool visited[14][8] = {};
  queue<pii> q;
  vector<pii> seq;

  q.push({y, x});
  seq.push_back({y, x});
  visited[y][x] = true;

  while (!q.empty()) {
    pii p = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int ny = dy[i] + p.first;
      int nx = dx[i] + p.second;
      if (visited[ny][nx]) continue;
      if (arr[ny][nx] == '.') continue;
      if (arr[y][x] == arr[ny][nx]) {
        visited[ny][nx] = true;
        q.push({ny, nx});
        seq.push_back({ny, nx});
      }
    }
  }
  if (seq.size() < 4) return false;
  for (pii p : seq) {
    arr[p.first][p.second] = '.';
  }
  return true;
}

bool crack() {
  bool ret = false;
  for (int j = 1; j <= H; j++) {
    for (int i = 1; i <= W; i++) {
      if (arr[j][i] != '.' && bfs(j, i)) ret = true;
    }
  }
  return ret;
}

void falldown() {
  for (int i = 1; i <= W; i++) {
    for (int j = 1; j < H; j++) {
      if (arr[j][i] == '.') {
        for (int k = j + 1; k <= H; k++) {
          if (arr[k][i] != '.') {
            swap(arr[j][i], arr[k][i]);
            break;
          }
        }
      }
    }
  }
}

void solve() {
  while (crack()) {
    ans++;
    falldown();
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  fill_n(arr[0], 14 * 8, '.');
  for (int j = H; j >= 1; j--) {
    for (int i = 1; i <= W; i++) {
      cin >> arr[j][i];
    }
  }

  solve();
}

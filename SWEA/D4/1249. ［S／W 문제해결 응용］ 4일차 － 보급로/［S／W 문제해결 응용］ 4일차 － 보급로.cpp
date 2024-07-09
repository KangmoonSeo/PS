#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> pipii;

int T;
int n;  // n * n plane
int arr[102][102] = {};
int dist[102][102] = {};  // {1, 1} 과의 최소 거리

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {-1, 0, 1, 0};

int solve() {
  cin >> n;
  fill_n(arr[0], 102 * 102, 1e9);
  fill_n(dist[0], 102 * 102, 1e9);

  string str;
  for (int j = 1; j <= n; j++) {
    cin >> str;
    for (int i = 0; i < n; i++) {
      arr[j][i + 1] = str[i] - '0';
    }
  }

  priority_queue<pipii, vector<pipii>, greater<pipii>> pq;

  dist[1][1] = 0;
  pq.push({0, {1, 1}});

  while (!pq.empty()) {
    int y = pq.top().second.first;
    int x = pq.top().second.second;
    pq.pop();

    for (int i = 0; i < 4; i++) {
      int ny = dy[i] + y;
      int nx = dx[i] + x;
      if (ny < 1 || ny > n || nx < 1 || nx > n) continue;

      int nxt = dist[y][x] + arr[ny][nx];
      if (nxt >= dist[ny][nx]) continue;
      dist[ny][nx] = nxt;
      pq.push({nxt, {ny, nx}});
    }
  }

  return dist[n][n];
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> T;
  int aa = 0;

  for (int i = 1; i <= T; i++) {
    aa = solve();

    cout << "#" << i << " ";
    cout << aa << "\n";
  }
}

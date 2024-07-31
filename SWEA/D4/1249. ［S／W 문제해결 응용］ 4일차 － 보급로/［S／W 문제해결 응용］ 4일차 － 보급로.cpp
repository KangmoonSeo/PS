#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int n;
int arr[102][102];
int dist[102][102];
bool visited[102][102];

int solve() {
  fill_n(arr[0], 102 * 102, 1e9);
  fill_n(dist[0], 102 * 102, 1e9);
  fill_n(visited[0], 102 * 102, false);

  cin >> n;

  for (int j = 1; j <= n; j++) {
    string str;
    cin >> str;
    for (int i = 1; i <= n; i++) {
      arr[j][i] = str[i - 1] - '0';
    }
  }

  queue<pii> q;
  q.push({1, 1});
  visited[1][1] = true;
  dist[1][1] = arr[1][1];

  while (!q.empty()) {
    const pii p = q.front();
    q.pop();
    int cur = dist[p.first][p.second];

    for (int i = 0; i < 4; i++) {
      const int ny = dy[i] + p.first;
      const int nx = dx[i] + p.second;
      if (arr[ny][nx] > 1e8) continue;
      int nxt = cur + arr[ny][nx];
      if (nxt >= dist[ny][nx]) continue;
      dist[ny][nx] = nxt;
      q.push({ny, nx});
    }
  }

  return dist[n][n];
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */


  int T;
  cin >> T;
  for (int test_case = 1; test_case <= T; test_case++) {
    /* code */
    auto ret = solve();
    cout << "#" << test_case << " " << ret << "\n";
  }
}

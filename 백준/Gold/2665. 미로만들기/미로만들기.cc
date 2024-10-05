#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n;
int arr[52][52];
int dist[52][52];

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

void print() {
  for (int j = 1; j <= n; j++) {
    cout << "|";
    for (int i = 1; i <= n; i++) {
      int val = arr[j][i];
      string str = val > 1e8 ? "x" : to_string(val);
      cout << str << " ";
    }
    cout << "\n";
  }
  cout << "\n";
}

void dijkstra() {
  dist[1][1] = arr[1][1];
  priority_queue<pair<int, pii>, vector<pair<int, pii>>,
                 greater<pair<int, pii>>>
      pq;  // { distance, vertex }

  pq.push({dist[1][1], {1, 1}});

  while (!pq.empty()) {
    int cur_dist = pq.top().first;
    pii p = pq.top().second;
    pq.pop();

    if (p.first == n && p.second == n) break;

    for (int i = 0; i < 4; i++) {
      int ny = dy[i] + p.first;
      int nx = dx[i] + p.second;

      int new_dist = cur_dist + arr[ny][nx];
      if (new_dist > 1e7) continue;

      if (new_dist < dist[ny][nx]) {
        dist[ny][nx] = new_dist;
        pq.push({new_dist, {ny, nx}});
      }
    }
  }
}

int solve() {
  /**
   * 미로만들기
   * 1,1 -> n,n
   * 최소 벽 부수기
   * -> dijkstra
   */
  fill_n(arr[0], 52 * 52, 1e9);
  fill_n(dist[0], 52 * 52, 1e9);

  for (int j = 1; j <= n; j++) {
    string str;
    cin >> str;
    for (int i = 1; i <= n; i++) {
      int input = str[i - 1];
      arr[j][i] = 1 - input + '0';
    }
  }

  dijkstra();
  return dist[n][n];
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n;
  int ans = solve();
  cout << ans << "\n";
}

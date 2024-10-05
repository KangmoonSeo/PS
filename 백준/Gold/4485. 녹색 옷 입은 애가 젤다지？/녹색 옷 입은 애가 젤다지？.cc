#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int test_case = 0;
int n;
int arr[127][127];
int dist[127][127];

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

void print() {
  for (int j = 1; j <= n; j++) {
    cout << "|";
    for (int i = 1; i <= n; i++) {
      int val = dist[j][i];
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
      //      cout << ny << "|" << nx << "|" << cur_dist << "|" << arr[ny][nx]
      //      << "\n";
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
   * 도둑루피만 가득한 방
   * 1,1 -> n,n
   * 잃는 금액 최소로
   * prints 최소 금액
   * -> dijkstra
   */
  fill_n(arr[0], 127 * 127, 1e9);
  fill_n(dist[0], 127 * 127, 1e9);

  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= n; i++) {
      cin >> arr[j][i];
    }
  }

  dijkstra();
  return dist[n][n];
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  while (true) {
    cin >> n;  // <= 125
    if (n == 0) break;
    test_case++;
    int ans = solve();
    cout << "Problem " << test_case << ": " << ans << "\n";
  }
}

#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int n, arr[102][102];
int dist[102][102];

void dijkstra() {
  priority_queue<pair<int, pii>, vector<pair<int, pii>>,
                 greater<pair<int, pii>>>
      pq;

  dist[1][1] = 0;
  pq.push({dist[1][1], {1, 1}});

  while (!pq.empty()) {
    auto p = pq.top();
    pq.pop();
    int cur = p.first;

    for (int i = 0; i < 4; i++) {
      int ny = dy[i] + p.second.first;
      int nx = dx[i] + p.second.second;
      if (arr[ny][nx] > 1e8) continue;

      int new_dist = p.first + arr[ny][nx];
      if (dist[ny][nx] <= new_dist) continue;

      dist[ny][nx] = new_dist;
      pq.push({dist[ny][nx], {ny, nx}});
    }
  }
}
int solve() {
  fill_n(arr[0], 102 * 102, 1e9);
  fill_n(dist[0], 102 * 102, 1e9);
  cin >> n;

  string input;
  for (int j = 1; j <= n; j++) {
    cin >> input;
    for (int i = 1; i <= n; i++) {
      arr[j][i] = (input[i - 1] - '0');
    }
  }
  dijkstra();
  return dist[n][n];
}

int main(int argc, char** argv) {
  int test_case;
  int T;

  cin >> T;
  /*
     여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
  */
  for (test_case = 1; test_case <= T; ++test_case) {
    int ans = solve();

    cout << "#" << test_case << " " << ans << "\n";
  }
  return 0;  // 정상종료시 반드시 0을 리턴해야합니다.
}
#include <bits/stdc++.h>
using namespace std;
#define y first
#define x second
typedef pair<int, int> pii;
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int n, m;
int arr[52][52] = {};
bool visited[52][52] = {};
vector<pii> store;
vector<vector<int> > candidates;
queue<pair<int, pii> > q;  // {dist, {y, x} }

vector<int> BT;
void chooseM(int init = 0, int TTL = 0) {
  if (TTL == m) {
    candidates.push_back(BT);
    return;
  }
  for (int i = init; i < store.size(); i++) {
    BT.push_back(i);
    chooseM(i + 1, TTL + 1);
    BT.pop_back();
  }
}

int bfs() {
  int ret = 0;
  while (!q.empty()) {
    int dist = q.front().first;
    pii p = q.front().second;
    q.pop();
    visited[p.y][p.x] = true;
    if (arr[p.y][p.x] == 1) {
      ret += dist;
    }
    for (int i = 0; i < 4; i++) {
      int ny = dy[i] + p.y;
      int nx = dx[i] + p.x;
      if (nx < 0 || nx > n || ny < 0 || ny > n) continue;
      if (!visited[ny][nx]) {
        visited[ny][nx] = true;
        q.push({dist + 1, {ny, nx}});
      }
    }
  }
  return ret;
}

void solve() {
  int ans = 1e9;
  chooseM();
  for (int i = 0; i < candidates.size(); i++) {
    q = queue<pair<int, pii> >();
    fill_n(visited[0], 52 * 52, false);
    for (int j = 0; j < candidates[i].size(); j++) {
      q.push({0, store[candidates[i][j]]});
    }
    ans = min(ans, bfs());
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n >> m;
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= n; i++) {
      cin >> arr[j][i];
      if (arr[j][i] == 2) store.push_back({j, i});
    }
  }
  solve();
}

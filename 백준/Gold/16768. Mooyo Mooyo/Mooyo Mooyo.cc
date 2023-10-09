#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};
int N, K;
const int W = 10;

int arr[102][12];

bool bfs(int y, int x) {
  bool visited[102][12] = {};
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
      if (arr[ny][nx] == 0) continue;
      if (arr[y][x] == arr[ny][nx]) {
        visited[ny][nx] = true;
        q.push({ny, nx});
        seq.push_back({ny, nx});
      }
    }
  }
  if (seq.size() < K) return false;
  for (pii p : seq) {
    arr[p.first][p.second] = 0;
  }
  return true;
}

bool crack() {
  bool ret = false;
  for (int j = 1; j <= N; j++) {
    for (int i = 1; i <= W; i++) {
      if (arr[j][i] > 0 && bfs(j, i)) ret = true;
    }
  }
  return ret;
}

void falldown() {
  for (int i = 1; i <= W; i++) {
    for (int j = 1; j < N; j++) {
      if (arr[j][i] == 0) {
        for (int k = j + 1; k <= N; k++) {
          if (arr[k][i] != 0) {
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
    falldown();
  }
  for (int j = N; j >= 1; j--) {
    for (int i = 1; i <= W; i++) {
      cout << arr[j][i];
    }
    cout << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */
  cin >> N >> K;
  fill_n(arr[0], 102 * 12, 0);
  string str;
  for (int j = N; j >= 1; j--) {
    cin >> str;
    for (int i = 1; i <= W; i++) {
      arr[j][i] = str[i - 1] - '0';
    }
  }

  solve();
}

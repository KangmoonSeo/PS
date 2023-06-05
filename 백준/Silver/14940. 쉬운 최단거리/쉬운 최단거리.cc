#include <bits/stdc++.h>
using namespace std;
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int n, m;
int init[2] = {};
int arr[1001][1001] = {};
bool visited[1001][1001] = {};
void print() {
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= m; i++) {
      if (!visited[j][i]) {
        cout << "-1 ";
      } else {
        cout << arr[j][i] << " ";
      }
    }
    cout << "\n";
  }
}
void solve() {
  //
  queue<pair<int, int> > q;
  q.push(make_pair(init[0], init[1]));
  visited[init[0]][init[1]] = true;
  arr[init[0]][init[1]] = 0;
  while (!q.empty()) {
    pair<int, int> p = q.front();
    int val = arr[p.first][p.second];
    q.pop();
    for (int i = 0; i < 4; i++) {
      int ny = p.first + dy[i];
      int nx = p.second + dx[i];
      if (!visited[ny][nx] && arr[ny][nx] != 0) {
        visited[ny][nx] = true;
        arr[ny][nx] = val + 1;
        q.push(make_pair(ny, nx));
      }
    }
  }
  //
  print();
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n >> m;
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= m; i++) {
      cin >> arr[j][i];
      if (arr[j][i] == 0) {
        visited[j][i] = true;
      }
      if (arr[j][i] == 2) {
        init[0] = j, init[1] = i;
      }
    }
  }
  solve();
}

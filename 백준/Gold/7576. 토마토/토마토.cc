#include <bits/stdc++.h>
using namespace std;

const int dy[4] = {1, 0, -1, 0};
const int dx[4] = {0, 1, 0, -1};
int y, x;

void tomato() {
  vector<vector<int> > arr(1002, vector<int>(1002, -1));
  queue<pair<int, int> > q;
  int ans = 1;
  // input
  for (int j = 1; j <= y; j++) {
    for (int i = 1; i <= x; i++) {
      cin >> arr[j][i];
      if (arr[j][i] == 1) {
        q.push(make_pair(j, i));
      }
    }
  }
  // bfs
  while (!q.empty()) {
    pair<int, int> p = q.front();
    int py = p.first;
    int px = p.second;
    ans = arr[py][px];
    q.pop();
    for (int d = 0; d < 4; d++) {
      if (arr[py + dy[d]][px + dx[d]] == 0) {
        arr[py + dy[d]][px + dx[d]] = ans + 1;
        q.push(make_pair(py + dy[d], px + dx[d]));
      }
    }
  }
  // exception
  for (int j = 1; j <= y; j++) {
    for (int i = 1; i <= x; i++) {
      if (arr[j][i] == 0) {
        cout << "-1\n";
        return;
      }
    }
  }
  // ans
  cout << ans - 1 << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> x >> y;
  tomato();
}

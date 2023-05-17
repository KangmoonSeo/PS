#include <bits/stdc++.h>
using namespace std;

const int dz[6] = {1, 0, 0, -1, 0, 0};
const int dy[6] = {0, 1, 0, 0, -1, 0};
const int dx[6] = {0, 0, 1, 0, 0, -1};
int z, y, x;
int arr[102][102][102];
void tomato() {
  fill_n(arr[0][0], 102 * 102 * 102, -1);
  queue<tuple<int, int, int> > q;
  int ans = 1;
  // input
  for (int k = 1; k <= z; k++) {
    for (int j = 1; j <= y; j++) {
      for (int i = 1; i <= x; i++) {
        cin >> arr[k][j][i];
        if (arr[k][j][i] == 1) {
          q.push({k, j, i});
        }
      }
    }
  }
  // bfs
  while (!q.empty()) {
    tuple<int, int, int> p = q.front();
    int pz = get<0>(p);
    int py = get<1>(p);
    int px = get<2>(p);
    ans = arr[pz][py][px];
    q.pop();
    for (int d = 0; d < 6; d++) {
      if (arr[pz + dz[d]][py + dy[d]][px + dx[d]] == 0) {
        arr[pz + dz[d]][py + dy[d]][px + dx[d]] = ans + 1;
        q.push({pz + dz[d], py + dy[d], px + dx[d]});
      }
    }
  }
  // exception
  for (int k = 1; k <= z; k++) {
    for (int j = 1; j <= y; j++) {
      for (int i = 1; i <= x; i++) {
        if (arr[k][j][i] == 0) {
          cout << "-1\n";
          return;
        }
      }
    }
  }
  // ans
  cout << ans - 1 << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> x >> y >> z;
  tomato();
}

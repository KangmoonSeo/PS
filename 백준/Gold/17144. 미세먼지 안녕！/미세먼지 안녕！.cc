#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {-1, 0, 1, 0};

int r, c, t;
int arr[52][52];
int adder[52][52];
int cleaner[2];

void bloom() {
  fill_n(adder[0], 52 * 52, 0);
  for (int j = 1; j <= r; j++) {
    for (int i = 1; i <= c; i++) {
      if (arr[j][i] <= 0) continue;
      int val = arr[j][i] / 5;
      for (int d = 0; d < 4; d++) {
        int ny = dy[d] + j;
        int nx = dx[d] + i;
        if (arr[ny][nx] >= 0) {
          adder[ny][nx] += val;
          arr[j][i] -= val;
        }
      }
    }
  }
  for (int j = 1; j <= r; j++) {
    for (int i = 1; i <= c; i++) {
      arr[j][i] += adder[j][i];
    }
  }
}
void clean() {
  for (int j = cleaner[0] - 1; j > 1; j--) {
    arr[j][1] = arr[j - 1][1];
  }
  for (int j = cleaner[1] + 1; j < r; j++) {
    arr[j][1] = arr[j + 1][1];
  }
  for (int i = 1; i < c; i++) {
    arr[1][i] = arr[1][i + 1];
    arr[r][i] = arr[r][i + 1];
  }
  for (int j = 1; j < cleaner[0]; j++) {
    arr[j][c] = arr[j + 1][c];
  }
  for (int j = r; j > cleaner[1]; j--) {
    arr[j][c] = arr[j - 1][c];
  }
  for (int i = c; i > 2; i--) {
    arr[cleaner[0]][i] = arr[cleaner[0]][i - 1];
    arr[cleaner[1]][i] = arr[cleaner[1]][i - 1];
  }
  arr[cleaner[0]][2] = 0;
  arr[cleaner[1]][2] = 0;
}
int calc() {
  int ret = 0;
  for (int j = 1; j <= r; j++) {
    for (int i = 1; i <= c; i++) {
      if (arr[j][i] > 0) ret += arr[j][i];
    }
  }
  return ret;
}
void solve() {
  cleaner[0] = cleaner[1] - 1;
  while (t--) {
    bloom();
    clean();
  }
  int ans = calc();
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> r >> c >> t;
  fill_n(arr[0], 52 * 52, -1e4);
  for (int j = 1; j <= r; j++) {
    for (int i = 1; i <= c; i++) {
      cin >> arr[j][i];
      if (arr[j][i] == -1) cleaner[1] = j;
    }
  }
  solve();
}

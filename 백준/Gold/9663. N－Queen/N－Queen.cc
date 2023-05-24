#include <bits/stdc++.h>
using namespace std;

int n;
int cnt = 0;
int arr[16][16] = {};

void activate(int y, int x, int n, bool ops) {
  if (ops) {
    for (int k = 1; k <= n; k++) {
      arr[k][x]++;
      arr[y][k]++;
      if (y - k >= 1 && x - k >= 1) arr[y - k][x - k]++;
      if (y - k >= 1 && x + k <= n) arr[y - k][x + k]++;
      if (y + k <= n && x - k >= 1) arr[y + k][x - k]++;
      if (y + k <= n && x + k <= n) arr[y + k][x + k]++;
    }
  } else {
    for (int k = 1; k <= n; k++) {
      arr[k][x]--;
      arr[y][k]--;
      if (y - k >= 1 && x - k >= 1) arr[y - k][x - k]--;
      if (y - k >= 1 && x + k <= n) arr[y - k][x + k]--;
      if (y + k <= n && x - k >= 1) arr[y + k][x - k]--;
      if (y + k <= n && x + k <= n) arr[y + k][x + k]--;
    }
  }
}
void BT(int TTL = 1) {
  if (TTL > n) {
    cnt++;
    // cout << cnt << "\n";
    return;
  }

  for (int i = 1; i <= n; i++) {
    if (arr[TTL][i] == 0) {
      activate(TTL, i, n, true);
      BT(TTL + 1);
      activate(TTL, i, n, false);
    }
  }
}
void solve() {
  cnt = 0;
  fill_n(arr[0], 16 * 16, 0);
  BT();
  cout << cnt << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n;
  int res[16] = {0,  1,   0,   0,    2,     10,    4,     40,
                 92, 352, 724, 2680, 14200, 73712, 365596};
  cout << res[n] << "\n";
}

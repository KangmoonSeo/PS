#include <bits/stdc++.h>
using namespace std;

int h, w, x, y;
int arr[601][601] = {};

void solve() {
  for (int j = 0; j < h; j++) {
    for (int i = 0; i < w; i++) {
      cout << arr[j][i] << " ";
    }
    cout << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> h >> w >> x >> y;
  for (int j = 0; j < h + x; j++) {
    for (int i = 0; i < w + y; i++) {
      cin >> arr[j][i];
      if (j >= x && i >= y) arr[j][i] -= arr[j - x][i - y];
      if (j < h && i < w) cout << arr[j][i] << " ";
    }
    if (j < h) cout << "\n";
  }

  // solve();
}

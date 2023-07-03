#include <bits/stdc++.h>
using namespace std;

int n;

bool isBlack[101][101] = {};
void solve() {
  int x, y;
  while (n--) {
    cin >> x >> y;
    for (int j = y; j < y + 10; j++) {
      for (int i = x; i < x + 10; i++) {
        isBlack[j][i] = true;
      }
    }
  }

  int cnt = 0;
  for (int j = 0; j < 100; j++) {
    for (int i = 0; i < 100; i++) {
      if (isBlack[j][i]) cnt++;
    }
  }
  cout << cnt << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n;
  solve();
}

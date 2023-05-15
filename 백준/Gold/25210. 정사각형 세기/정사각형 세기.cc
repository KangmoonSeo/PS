#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
  vector<vector<int> > p(5, vector<int>(4));
  for (int i = 1; i <= 4; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> p[i][j];
    }
  }

  int minLx = min(p[2][0], p[3][0]);
  int minRx = max(p[1][0], p[4][0]);
  int minUy = max(p[1][1], p[2][1]);
  int minDy = min(p[3][1], p[4][1]);

  int maxLx = max(p[2][2], p[3][2]);
  int maxRx = min(p[1][2], p[4][2]);
  int maxUy = min(p[1][3], p[2][3]);
  int maxDy = max(p[3][3], p[4][3]);

  int minlen = max(minRx - minLx, minUy - minDy);
  int maxlen = min(maxRx - maxLx, maxUy - maxDy);

  ll ans = 0;
  for (int len = minlen; len <= maxlen; len++) {
    ll left = min(minLx, maxRx - len) - max(maxLx, minRx - len) + 1;
    ll right = min(maxRx, minLx + len) - max(minRx, (maxLx + len)) + 1;
    ll up = min(maxUy, minDy + len) - max(minUy, (maxDy + len)) + 1;
    ll down = min(minDy, maxUy - len) - max(maxDy, minUy - len) + 1;
    ans += max(0LL, min(left, right)) * max(0LL, min(up, down));
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  solve();
}

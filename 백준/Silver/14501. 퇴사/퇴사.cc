#include <bits/stdc++.h>
using namespace std;

int n, t[1001], p[1001], ans = 0;

void task(int cur, int remain, int cost) {
  if (cur == n + 1) {
    ans = max(cost, ans);
    return;
  } else if (remain > 0) {
    task(cur + 1, remain - 1, cost);
    return;
  }
  task(cur + 1, 0, cost);

  if (cur + t[cur] > n + 1) {
    return;
  }
  task(cur + 1, t[cur] - 1, cost + p[cur]);
}
void solve() {
  task(0, 0, 0);
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> t[i] >> p[i];
  }

  solve();
}

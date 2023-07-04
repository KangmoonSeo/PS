#include <bits/stdc++.h>
using namespace std;

string a, b;
short dp[1001][1001] = {};

void track(int i, int j) {
  if (dp[i][j] == 0) return;
  if (a[i - 1] == b[j - 1]) {
    track(i - 1, j - 1);
    cout << a[i - 1];
  } else {
    if (dp[i - 1][j] > dp[i][j - 1])
      track(i - 1, j);
    else
      track(i, j - 1);
  }
}
void solve() {
  int a_len = a.size();
  int b_len = b.size();
  for (int i = 1; i <= a_len; i++) {
    for (int j = 1; j <= b_len; j++) {
      dp[i][j] = (a[i - 1] == b[j - 1]) ? dp[i - 1][j - 1] + 1
                                        : max(dp[i - 1][j], dp[i][j - 1]);
    }
  };
  cout << dp[a_len][b_len] << "\n";
  track(a_len, b_len);
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> a >> b;
  solve();
}

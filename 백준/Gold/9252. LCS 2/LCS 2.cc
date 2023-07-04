#include <bits/stdc++.h>
using namespace std;

string a, b;
string dp[2][1001];

void solve() {
  int a_len = a.size();
  int b_len = b.size();
  for (int i = 1; i <= a_len; i++) {
    int fl = i % 2;
    for (int j = 1; j <= b_len; j++) {
      if (a[i - 1] == b[j - 1]) {
        dp[fl][j] = dp[1 - fl][j - 1];
        dp[fl][j] += a[i - 1];
      } else if (dp[1 - fl][j].size() >= dp[fl][j - 1].size()) {
        dp[fl][j] = dp[1 - fl][j];
      } else {
        dp[fl][j] = dp[fl][j - 1];
      }
    }
  };
  cout << dp[a_len % 2][b_len].size() << "\n" << dp[a_len % 2][b_len] << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> a >> b;
  solve();
}

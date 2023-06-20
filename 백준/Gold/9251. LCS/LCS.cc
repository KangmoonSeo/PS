#include <bits/stdc++.h>
using namespace std;

string a;
string b;
int dp[1001][1001] = {};

void solve() {
  int a_len = a.size();
  int b_len = b.size();
  for (int i = 1; i <= a_len; i++) {
    for (int j = 1; j <= b_len; j++) {
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
    }
  }
  cout << dp[a_len][b_len] << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> a >> b;
  solve();
}

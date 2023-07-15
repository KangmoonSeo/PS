#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[2001] = {};
bool dp[2001][2001] = {};

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  for (int i = 1; i <= n; i++) {
    dp[i][i] = true;  // m = 1
    if (arr[i - 1] == arr[i]) {
      dp[i - 1][i] = true;  // m = 2
    }
  }
  for (int gap = 2; gap < n; gap++) {  // m > 2
    for (int i = 1; i <= n - gap; i++) {
      int j = i + gap;
      if (arr[i] == arr[j] && dp[i + 1][j - 1]) {
        dp[i][j] = true;
      }
    }
  }

  cin >> m;
  int s, e;
  while (m--) {
    cin >> s >> e;
    dp[s][e] ? cout << "1\n" : cout << "0\n";
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  solve();
}

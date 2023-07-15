#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[2001];
bool dp[2001][2001] = {};

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  for (int gap = 0; gap < n; gap++) {
    for (int s = 1; s <= n - gap; s++) {
      int e = s + gap;
      if (arr[s] == arr[e] && (gap < 2 || dp[s + 1][e - 1])) dp[s][e] = true;
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

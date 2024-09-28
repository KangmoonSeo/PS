#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;

ll arr[91][2];

void solve() {
  // n : 1
  arr[1][0] = 0;
  arr[1][1] = 1;

  for (int i = 2; i <= n; i++) {
    arr[i][0] = arr[i - 1][0] + arr[i - 1][1];
    arr[i][1] = arr[i - 1][0];
  }

  ll ans = arr[n][0] + arr[n][1];

  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */
  //  freopen("sample_input.txt", "r", stdin);

  cin >> n;
  solve();
}

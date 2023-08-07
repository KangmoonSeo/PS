#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1000001], ans[1000001];

void solve() {
  int mem = -1;
  for (int i = n; i >= 1; i--) {
    ans[i] = mem;
    if (arr[i - 1] != arr[i]) mem = i;
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  solve();
}

#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[100001];
void solve() {
  // function works here
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  cin >> m;
  int cmp;
  while (m--) {
    cin >> cmp;
    cout << (binary_search(arr, arr + n, cmp) ? "1\n" : "0\n");
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  solve();
}

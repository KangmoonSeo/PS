#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, v, arr[200001];

void solve() {
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  ll l = v - 1;
  ll r = n - v + 1;

  ll input;
  while (m--) {
    cin >> input;
    ll ans;
    if (input < n) {
      ans = input;
    } else {
      ans = (input - l) % r + l;
    }
    cout << arr[ans] << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n >> m >> v;
  solve();
}

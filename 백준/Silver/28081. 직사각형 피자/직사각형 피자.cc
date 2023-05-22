#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int w, h;  // w:가로 길이, h:세로 길이, k:먹을 수 있는 최대 크기(k 초과면 x)
ll k;
int n, m;

void solve() {
  cin >> w >> h >> k;
  cin >> n;
  vector<ll> y(n + 1);
  // y
  for (int j = 0; j < n; j++) {
    cin >> y[j];
  }
  y[n] = h;
  for (int j = 0; j < n; j++) {
    y[n - j] = y[n - j] - y[n - 1 - j];
  }

  // x
  cin >> m;
  vector<ll> x(m + 1);
  for (int i = 0; i < m; i++) {
    cin >> x[i];
  }
  x[m] = w;
  for (int i = 0; i < m; i++) {
    x[m - i] = x[m - i] - x[m - 1 - i];
  }
  sort(x.begin(), x.end());
  // O(n+m)

  ll ans = 0;
  for (int j = 0; j <= n; j++) {  // O(nm) -> O(nlogm)으로 줄여야 함
    ll target = (k / y[j]);
    ll cnt = upper_bound(x.begin(), x.end(), target) - x.begin();
    if (x[cnt] == target) cnt++;
    ans += cnt;
  }
  cout << ans << "\n";
}
int main() {
  //
  solve();
}
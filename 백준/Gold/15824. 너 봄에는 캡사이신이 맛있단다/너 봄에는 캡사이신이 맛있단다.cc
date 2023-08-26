#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DIV 1'000'000'007
int n, arr[300001];
ll dist[300001] = {}, pows[300001] = {};

ll getPow(int v) {
  if (pows[v] > 0) return pows[v];
  int h = v / 2;
  ll res = getPow(h);
  pows[v] = res * res;
  if (v % 2 == 1) pows[v] *= 2;
  pows[v] %= DIV;
  return pows[v];
}
void solve() {
  pows[0] = 1;
  pows[1] = 2;
  sort(arr, arr + n);

  for (int i = 1; i <= n / 2; i++) {
    int j = n - i;
    dist[i] = arr[j] - arr[i - 1];
    dist[i] += dist[i - 1];
    dist[i] %= DIV;
    dist[j] = dist[i];
  }

  ll ans = 0;
  for (ll i = 1; i <= n - 1; i++) {
    ll w = getPow(i - 1);
    ans += (w * dist[i]) % DIV;
    ans %= DIV;
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  solve();
}

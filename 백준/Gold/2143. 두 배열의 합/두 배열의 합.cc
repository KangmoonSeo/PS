#include <bits/stdc++.h>

#include <unordered_map>
using namespace std;
typedef long long ll;

ll T, n, m;
ll a[1001] = {};
ll b[1001] = {};
unordered_map<ll, ll> aa;
unordered_map<ll, ll> bb;

void solve() {
  cin >> T;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += a[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      aa[a[i] - a[j]]++;
    }
  }

  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    b[i] += b[i - 1];
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < i; j++) {
      bb[b[i] - b[j]]++;
    }
  }
  ll ans = 0;
  for (auto it : aa) {
    if (bb[T - it.first] > 0) { 
      ans += it.second * bb[T - it.first];
    }
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  solve();
}

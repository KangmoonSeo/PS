#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;

int T, n, m;
int a[1001] = {};
int b[1001] = {};
unordered_map<int, int> aa;
unordered_map<int, int> bb;

void solve() {
  cin >> T >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += a[i - 1];
    for (int j = 0; j < i; j++) {  // O(N^2)
      aa[a[i] - a[j]]++;
    }
  }

  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    b[i] += b[i - 1];
    for (int j = 0; j < i; j++) {  // O(M^2)
      bb[b[i] - b[j]]++;
    }
  }

  ll ans = 0;
  for (auto it : aa) {  // O(N^2)
    if (bb[T - it.first] > 0) {
      ans += (ll)it.second * (ll)bb[T - it.first];
    }
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  solve();
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

void solve() {
  int t;
  ll input;
  while (n--) {
    cin >> t;
    int half = t / 2 + 1;
    unordered_map<ll, int> m;
    bool isTermiated = false;
    ll ans = 0;
    for (int i = 0; i < t; i++) {
      cin >> input;
      m[input]++;
      if (m[input] >= half) {
        isTermiated = true;
        ans = input;
      }
    }
    if (isTermiated) {
      cout << ans << "\n";
    } else {
      cout << "SYJKGW\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n;
  solve();
}

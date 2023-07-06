#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int T, n, m;
int a[1001] = {};
int b[1001] = {};
vector<int> aa;
vector<int> bb;

void solve() {
  cin >> T >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += a[i - 1];
    for (int j = 0; j < i; j++) {
      aa.push_back(a[i] - a[j]);
    }
  }

  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    b[i] += b[i - 1];
    for (int j = 0; j < i; j++) {
      bb.push_back(b[i] - b[j]);
    }
  }
  sort(aa.begin(), aa.end());
  reverse(aa.begin(), aa.end());
  sort(bb.begin(), bb.end());

  ll ans = 0;
  int nxt = 0;
  for (int val : aa) {  // O(NlogM)
    int target = T - val;
    auto it = lower_bound(bb.begin() + nxt, bb.end(), target);
    ans += upper_bound(bb.begin() + nxt, bb.end(), target) - it;
    nxt = it - bb.begin();
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */
  solve();
}

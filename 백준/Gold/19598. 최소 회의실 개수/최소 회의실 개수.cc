#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n;

vector<pii> vec;

void solve() {
  sort(vec.begin(), vec.end());

  int cnt = 0, ans = 0;

  for (pii p : vec) {
    int x = p.first;
    cnt += p.second;
    ans = max(ans, cnt);
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n;
  int u, v;
  for (int i = 0; i < n; i++) {
    cin >> u >> v;
    vec.push_back({u, +1});
    vec.push_back({v, -1});
  }

  solve();
}

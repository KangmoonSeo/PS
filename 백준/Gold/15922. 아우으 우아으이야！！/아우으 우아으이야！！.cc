#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n;

vector<pii> vec;

void solve() {
  sort(vec.begin(), vec.end());

  int mem = -1;
  int cnt = 0;
  int ans = 0;

  for (pii p : vec) {
    int x = p.first;
    cnt += p.second;

    if (p.second > 0 && cnt == 1) {  // cnt goes 0->1
      mem = x;
    }
    if (p.second < 0 && cnt == 0) {  // terminates
      ans += x - mem;
    }
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

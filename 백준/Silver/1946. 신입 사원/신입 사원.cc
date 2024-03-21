#include <bits/stdc++.h>
using namespace std;

int n;

vector<pair<int, int> > vec;

void solve() {
  // function works here
  //
  int S, M;
  for (int i = 0; i < n; i++) {
    cin >> S >> M;
    vec.push_back({S, M});
  }

  sort(vec.begin(), vec.end());

  int ans = 0;
  int mem = 1e9;
  for (auto p : vec) {
    if (mem > p.second) {
      mem = p.second;
      ans++;
    }
    vec.pop_back();
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  int T;
  cin >> T;

  while (T--) {
    cin >> n;
    solve();
  }
}

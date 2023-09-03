#include <bits/stdc++.h>
using namespace std;

int n, m[100001];

void solve() {
  int input;
  for (int i = 1; i <= n; i++) {
    cin >> input;
    m[input] = i;
  }

  vector<int> vec;
  for (int i = 1; i <= n; i++) {
    cin >> input;
    int cur = m[input];
    if (vec.empty() || vec.back() < cur) {
      vec.push_back(cur);
    } else {
      int prev = lower_bound(vec.begin(), vec.end(), cur) - vec.begin();
      vec[prev] = cur;
    }
  }
  int ans = vec.size();
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n;
  solve();
}

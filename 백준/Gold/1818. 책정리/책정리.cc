#include <bits/stdc++.h>
using namespace std;

int n, arr[200001];
vector<int> vec;

void solve() {
  for (int i = 1; i <= n; i++) {
    int cur = arr[i];
    if (vec.empty() || vec.back() < cur) {
      vec.push_back(cur);
    } else {
      int prev = lower_bound(vec.begin(), vec.end(), cur) - vec.begin();
      vec[prev] = cur;
    }
  }
  int ans = n - vec.size();
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  solve();
}

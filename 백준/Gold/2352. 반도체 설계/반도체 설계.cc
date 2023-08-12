#include <bits/stdc++.h>
using namespace std;

int n, arr[40001];
vector<int> seq;
void solve() {
  for (int i = 1; i <= n; i++) {
    int cur = arr[i];
    if (seq.empty() || seq.back() < cur) {
      seq.push_back(cur);
    } else {
      int prev = lower_bound(seq.begin(), seq.end(), cur) - seq.begin();
      seq[prev] = cur;
    }
  }
  cout << seq.size() << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  solve();
}

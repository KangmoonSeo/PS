#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, input;

  cin >> n;
  vector<int> seq;
  for (int i = 0; i < n; i++) {
    cin >> input;
    if (seq.empty() || seq.back() < input) {
      seq.push_back(input);
    } else {
      int x = lower_bound(seq.begin(), seq.end(), input) - seq.begin();
      seq[x] = input;
    }
  }
  cout << seq.size() << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}

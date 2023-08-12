#include <bits/stdc++.h>
using namespace std;

int n;
void solve() {
  vector<int> seq;
  for (int i = 1; i <= n; i++) {
    int input;
    cin >> input;
    if (seq.empty() || seq.back() < input) {
      seq.push_back(input);
    } else {
      int prev = lower_bound(seq.begin(), seq.end(), input) - seq.begin();
      seq[prev] = input;
    }
  }
  cout << seq.size() << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  while (cin >> n) {
    solve();
  }
}

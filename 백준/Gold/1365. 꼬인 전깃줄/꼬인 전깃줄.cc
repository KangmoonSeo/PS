#include <bits/stdc++.h>
using namespace std;

int n, arr[100001];
vector<int> seq;
void solve() {
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    if (seq.empty() || seq.back() < arr[i]) {
      seq.push_back(arr[i]);
    } else {
      int prev = lower_bound(seq.begin(), seq.end(), arr[i]) - seq.begin();
      seq[prev] = arr[i];
    }
  }
  cout << n - seq.size() << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n;
  solve();
}

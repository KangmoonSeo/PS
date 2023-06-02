#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int> > arr;

void solve() {
  sort(arr.begin(), arr.end());
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, arr[i].second - i);
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n;
  int input;
  for (int i = 0; i < n; i++) {
    cin >> input;
    arr.push_back(make_pair(input, i));
  }
  solve();
}
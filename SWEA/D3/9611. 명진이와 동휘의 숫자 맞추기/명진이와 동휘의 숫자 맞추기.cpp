#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, in[4];
  cin >> n;
  string str;
  vector<int> alist(10, 1);
  while (n--) {
    // input
    for (int i = 0; i < 4; i++) cin >> in[i];
    cin >> str;
    // calc
    if (str == "NO") {
      for (int i = 0; i < 4; i++) {
        alist[in[i]] = 0;
      }
    } else {
      for (int i = 0; i < 4; i++) {
        alist[in[i]] *= 2;
      }
    }
  }
  int ans, mem = 0;
  for (int i = 0; i < 10; i++) {
    if (mem < alist[i]) {
      ans = i;
      mem = alist[i];
    }
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cout << "#" << i << " ";
    solve();
  }
}

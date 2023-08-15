#include <bits/stdc++.h>
using namespace std;

string str;

int check(int l, int r, bool token = false) {
  while (l < r) {
    char ll = str[l];
    char rr = str[r];
    if (ll == rr) {
      l++;
      r--;
    } else {
      if (!token) return -1;
      if (check(l + 1, r) < 0 && check(l, r - 1) < 0) {
        return 2;
      } else {
        return 1;
      }
    }
  }
  return 0;
}

void solve() {
  int ans = check(0, str.size() - 1, true);
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  int T;
  cin >> T;

  while (T--) {
    cin >> str;
    solve();
  }
}

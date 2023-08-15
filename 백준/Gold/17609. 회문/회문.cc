#include <bits/stdc++.h>
using namespace std;

string str;

int check(int l, int r, bool token = false) {
  while (l < r) {
    if (str[l] == str[r]) {
      l++, r--;
    } else {
      if (!token) return -1;
      if (check(l + 1, r) < 0 && check(l, r - 1) < 0) return 2;
      return 1;
    }
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  int T;
  cin >> T;

  while (T--) {
    cin >> str;
    cout << check(0, str.size() - 1, true) << "\n";
  }
}

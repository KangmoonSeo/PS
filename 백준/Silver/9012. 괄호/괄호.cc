#include <bits/stdc++.h>
using namespace std;

int n;

bool solve() {
  // function works here

  string input;
  cin >> input;

  int cnt_l = 0;
  int cnt_r = 0;

  bool ans = true;
  for (int i = 0; i < input.size(); i++) {
    /* code */
    char c = input[i];
    if (c == '(') {
      cnt_l += 1;
    } else {
      cnt_r += 1;
    }

    if (cnt_r > cnt_l) {
      ans = false;
    }
  }

  if (cnt_r == cnt_l) {
    return ans;
  } else {
    return false;
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n;

  while (n--) {
    auto ans = solve();
    cout << (ans ? "YES" : "NO") << "\n";
  }
}

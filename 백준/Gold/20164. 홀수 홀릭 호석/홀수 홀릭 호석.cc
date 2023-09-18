#include <bits/stdc++.h>
using namespace std;

string str;
int ans[2] = {(int)(1e9), 0};  // [min, max]

int getValue(string s) {
  int ret = 0;
  for (char c : s) {
    if ((c - '0') % 2 == 1) ret++;
  }
  return ret;
}

void BT(string s, int tot = 0) {
  tot += getValue(s);
  int len = s.size();

  if (len <= 1) {
    ans[0] = min(ans[0], tot);
    ans[1] = max(ans[1], tot);

  } else if (len <= 2) {
    int v = (s[0] - '0') + (s[1] - '0');

    BT(to_string(v), tot);

  } else {
    string ns[3];
    for (int i = 1; i < len; i++) {
      for (int j = i + 1; j < len; j++) {
        if (j <= i || len <= j) continue;
        ns[0] = s.substr(0, i);
        ns[1] = s.substr(i, j - i);
        ns[2] = s.substr(j, len - j);

        int nxt = 0;
        for (int k = 0; k < 3; k++) {
          nxt += stoi(ns[k]);
        }

        BT(to_string(nxt), tot);
      }
    }
  }
}
void solve() {
  BT(str);
  for (int i = 0; i < 2; i++) {
    cout << ans[i] << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> str;
  solve();
}

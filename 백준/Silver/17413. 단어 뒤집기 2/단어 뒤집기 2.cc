#include <bits/stdc++.h>
using namespace std;

string str;

string rev(string s) {
  string ret;
  for (int i = s.size() - 1; i >= 0; i--) ret += s[i];
  return ret;
}
void solve() {
  string ans, tmp;

  bool isBrace = false;
  for (char c : str) {
    if (c == '<') {
      ans += rev(tmp);
      tmp = "";
      isBrace = true;
    }
    if (isBrace) {
      ans += c;
    }
    if (c == '>') {
      isBrace = false;
      continue;
    }
    if (isBrace) continue;

    if (c == ' ') {
      ans += rev(tmp);
      tmp = "";
      ans += c;
    } else {
      tmp += c;
    }
  }

  if (tmp != "") {
    ans += rev(tmp);
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  getline(cin, str);
  solve();
}

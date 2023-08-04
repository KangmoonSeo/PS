#include <bits/stdc++.h>
using namespace std;

string str;

void solve() {
  vector<char> vec;

  int ans = 0, mem = 1, i = 0;
  int length = str.size();

  for (i = 0; i < length; i++) {
    char c = str[i];
    if (c == '(') {
      mem *= 2;
      vec.push_back(c);
    } else if (c == '[') {
      mem *= 3;
      vec.push_back(c);
    } else if (c == ')') {
      if (vec.empty() || vec.back() != '(') break;
      if (str[i - 1] == '(') ans += mem;
      mem /= 2;
      vec.pop_back();
    } else if (c == ']') {
      if (vec.empty() || vec.back() != '[') break;
      if (str[i - 1] == '[') ans += mem;
      mem /= 3;
      vec.pop_back();
    }
  }
  if (!vec.empty() || i < length) ans = 0;
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> str;
  solve();
}

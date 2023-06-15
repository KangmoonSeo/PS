#include <bits/stdc++.h>
using namespace std;

string str;
void solve() {
  // function acts here
  //
  string mem = "";
  string ans = "";
  int length = str.size();
  ans += str[0];
  for (int i = 1; i < length; i++) {
    ans += str[i];

    if (str[i] == '=') {  // c=, s=, z=, dz=
      ans.pop_back();
      ans.pop_back();
      if (str[i - 1] == 'z' && i - 2 >= 0 && str[i - 2] == 'd') {
        ans.pop_back();
      }
      ans += "#";
    } else if (str[i] == '-') {  // c-, d-
      ans.pop_back();
      ans.pop_back();
      ans += "#";

    } else if (str[i] == 'j') {  // lj, nj
      if (str[i - 1] == 'l' || str[i - 1] == 'n') {
        ans.pop_back();
        ans.pop_back();
        ans += "#";
      }
    }
  }
  cout << ans.size() << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> str;
  solve();
}

#include <bits/stdc++.h>
using namespace std;

string str;
vector<string> vec;
vector<string> rev;

void solve() {
  int n = str.size();
  string mem = "";
  bool isRev = false;
  for (int i = 0; i < n; i++) {
    if (i > 0 && str[i] == ':' && str[i - 1] == ':') {
      isRev = true;
      if (mem == "") continue;
      vec.push_back(mem);
      mem = "";
    }
    if (str[i] == ':') {
      if (mem == "") continue;
      isRev ? rev.push_back(mem) : vec.push_back(mem);
      mem = "";
    } else {
      mem += str[i];
    }
  }
  if (mem != "") isRev ? rev.push_back(mem) : vec.push_back(mem);

  vector<string> ans;
  int k = 0;
  for (int i = 0; i < 8; i++) {
    if (i < vec.size()) {
      string tmp;
      int len = vec[i].size();
      if (len < 1) {
        tmp = "0000";
      } else if (len < 2) {
        tmp = "000" + vec[i];
      } else if (len < 3) {
        tmp = "00" + vec[i];
      } else if (len < 4) {
        tmp = "0" + vec[i];
      } else {
        tmp = vec[i];
      }
      ans.push_back(tmp);
    } else if (i < 8 - rev.size()) {
      ans.push_back("0000");
    } else {
      string tmp = rev[k];
      int len = rev[k].size();
      if (len < 1) {
        tmp = "0000";
      } else if (len < 2) {
        tmp = "000" + rev[k];
      } else if (len < 3) {
        tmp = "00" + rev[k];
      } else if (len < 4) {
        tmp = "0" + rev[k];
      } else {
        tmp = rev[k];
      }
      ans.push_back(tmp);
      k++;
    }
  }
  for (int i = 0; i < 8; i++) {
    cout << ans[i];
    if (i != 7) cout << ":";
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> str;
  solve();
}

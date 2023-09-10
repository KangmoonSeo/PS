#include <bits/stdc++.h>
using namespace std;

int n;
string str;
vector<string> vec;

void solve() {
  int len = n / 5;
  //
  string tmp;
  for (int i = 0; i < n; i++) {
    tmp += str[i];
    if ((i + 1) % len == 0) {
      vec.push_back(tmp);
      tmp = "";
    }
  }
  string ans = "";

  for (int i = 0; i < len; i++) {
    if (vec[0][i] == '.') continue;
    // check '1'
    if (i == len - 1 || vec[0][i + 1] == '.' && vec[4][i] != '.') {
      ans += "1";
      continue;
    } else if (vec[0].substr(i, 3) == "###" && true && true &&
               vec[1].substr(i, 3) == "..#" && true && true &&
               vec[2].substr(i, 3) == "###" && true && true &&
               vec[3].substr(i, 3) == "#.." && true && true &&
               vec[4].substr(i, 3) == "###") {
      ans += "2";
    } else if (vec[0].substr(i, 3) == "###" && true && true &&
               vec[1].substr(i, 3) == "..#" && true && true &&
               vec[2].substr(i, 3) == "###" && true && true &&
               vec[3].substr(i, 3) == "..#" && true && true &&
               vec[4].substr(i, 3) == "###") {
      ans += "3";
    } else if (vec[0].substr(i, 3) == "#.#" && true && true &&
               vec[1].substr(i, 3) == "#.#" && true && true &&
               vec[2].substr(i, 3) == "###" && true && true &&
               vec[3].substr(i, 3) == "..#" && true && true &&
               vec[4].substr(i, 3) == "..#") {
      ans += "4";
    } else if (vec[0].substr(i, 3) == "###" && true && true &&
               vec[1].substr(i, 3) == "#.." && true && true &&
               vec[2].substr(i, 3) == "###" && true && true &&
               vec[3].substr(i, 3) == "..#" && true && true &&
               vec[4].substr(i, 3) == "###") {
      ans += "5";
    } else if (vec[0].substr(i, 3) == "###" && true && true &&
               vec[1].substr(i, 3) == "#.." && true && true &&
               vec[2].substr(i, 3) == "###" && true && true &&
               vec[3].substr(i, 3) == "#.#" && true && true &&
               vec[4].substr(i, 3) == "###") {
      ans += "6";
    } else if (vec[0].substr(i, 3) == "###" && true && true &&
               vec[1].substr(i, 3) == "..#" && true && true &&
               vec[2].substr(i, 3) == "..#" && true && true &&
               vec[3].substr(i, 3) == "..#" && true && true &&
               vec[4].substr(i, 3) == "..#") {
      ans += "7";
    } else if (vec[0].substr(i, 3) == "###" && true && true &&
               vec[1].substr(i, 3) == "#.#" && true && true &&
               vec[2].substr(i, 3) == "###" && true && true &&
               vec[3].substr(i, 3) == "#.#" && true && true &&
               vec[4].substr(i, 3) == "###") {
      ans += "8";
    } else if (vec[0].substr(i, 3) == "###" && true && true &&
               vec[1].substr(i, 3) == "#.#" && true && true &&
               vec[2].substr(i, 3) == "###" && true && true &&
               vec[3].substr(i, 3) == "..#" && true && true &&
               vec[4].substr(i, 3) == "###") {
      ans += "9";
    } else if (vec[0].substr(i, 3) == "###" && true && true &&
               vec[1].substr(i, 3) == "#.#" && true && true &&
               vec[2].substr(i, 3) == "#.#" && true && true &&
               vec[3].substr(i, 3) == "#.#" && true && true &&
               vec[4].substr(i, 3) == "###") {
      ans += "0";
    }
    i++;
    i++;
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n;
  cin >> str;
  solve();
}

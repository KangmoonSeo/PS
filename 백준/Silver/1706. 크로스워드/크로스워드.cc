#include <bits/stdc++.h>
using namespace std;

int r, c;
char arr[22][22] = {};
vector<string> vec;
void solve() {
  string str;
  for (int i = 1; i <= c; i++) {
    str = "";
    for (int j = 1; j <= r; j++) {
      if (arr[j][i] == '#') {
        if (str.size() >= 2) vec.push_back(str);

        str = "";
        continue;
      }

      str += arr[j][i];
    }
    if (str.size() >= 2) vec.push_back(str);

    str = "";
  }
  for (int j = 1; j <= r; j++) {
    for (int i = 1; i <= c; i++) {
      if (arr[j][i] == '#') {
        if (str.size() >= 2) vec.push_back(str);
        str = "";
        continue;
      }
      str += arr[j][i];
    }
    if (str.size() >= 2) vec.push_back(str);
    str = "";
  }
  sort(vec.begin(), vec.end());
  cout << vec[0] << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  fill_n(arr[0], 22 * 22, '#');
  cin >> r >> c;

  string str;
  for (int j = 1; j <= r; j++) {
    cin >> str;
    for (int i = 1; i <= c; i++) {
      arr[j][i] = str[i - 1];
    }
  }

  solve();
}

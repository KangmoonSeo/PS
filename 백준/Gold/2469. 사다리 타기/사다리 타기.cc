#include <bits/stdc++.h>
using namespace std;

int k, n, target;
string want;
vector<string> vec;

string desc() {
  string cur;
  for (int i = 0; i < k; i++) {
    cur.push_back('A' + i);
  }

  for (int j = 0; j < n; j++) {
    for (int i = 0; i < k - 1; i++) {
      if (vec[j][i] == '?') return cur;
      if (vec[j][i] == '-') swap(cur[i], cur[i + 1]);
    }
  }
  return "ERROR";
}

string asc() {
  string cur = want;

  for (int j = n - 1; j >= 0; j--) {
    for (int i = 0; i < k - 1; i++) {
      if (vec[j][i] == '?') return cur;
      if (vec[j][i] == '-') swap(cur[i], cur[i + 1]);
    }
  }
  return "ERROR";
}
void solve() {
  string init = desc();
  string dest = asc();
  string ans;

  for (int i = 0; i < k - 1; i++) {
    if (init[i] == dest[i]) {
      ans += '*';
    } else if (init[i] == dest[i + 1] && init[i + 1] == dest[i]) {
      swap(dest[i], dest[i + 1]);
      ans += "-";
    } else {
      ans = "";
      for (int u = 0; u < k - 1; u++) ans += 'x';
      break;
    }
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> k >> n;
  cin >> want;

  string str;
  for (int j = 0; j < n; j++) {
    cin >> str;
    if (str[0] == '?') target = j;
    vec.push_back(str);
  }

  solve();
}

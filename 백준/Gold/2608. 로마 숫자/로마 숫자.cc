#include <bits/stdc++.h>
using namespace std;
map<char, int> m;
vector<pair<char, char> > vec;
string s1, s2;

void init() {
  m['I'] = 1, m['V'] = 5;
  m['X'] = 10, m['L'] = 50;
  m['C'] = 100, m['D'] = 500;
  m['M'] = 1000;
  vec.push_back({'I', 'V'});
  vec.push_back({'X', 'L'});
  vec.push_back({'C', 'D'});
  vec.push_back({'M', 'F'});
}

int convert(string s) {
  int ret = 0;
  int mem = 1e8;
  for (char c : s) {
    ret += m[c];
    if (mem < m[c]) ret -= mem * 2;
    mem = m[c];
  }
  return ret;
}
string convert(int _s) {
  string s = to_string(_s);
  reverse(s.begin(), s.end());
  string ret = "";
  for (int i = 0; i < s.size(); i++) {
    char one = vec[i].first;
    char five = vec[i].second;
    switch (s[i]) {
      case '3':
        ret += one;
      case '2':
        ret += one;
      case '1':
        ret += one;
      case '0':
        break;
      case '4':
        ret += five;
        ret += one;
        break;
      case '8':
        ret += one;
      case '7':
        ret += one;
      case '6':
        ret += one;
      case '5':
        ret += five;
        break;
      case '9':
        ret += vec[i + 1].first;
        ret += one;
        break;
    }
  }
  reverse(ret.begin(), ret.end());
  return ret;
}

void solve() {
  init();
  int i1 = convert(s1);
  int i2 = convert(s2);

  int ans = i1 + i2;
  cout << ans << "\n";
  cout << convert(ans) << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> s1 >> s2;
  solve();
}

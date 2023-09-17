#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

map<string, pii> m;
string king, dol;

pii u, v;
int n;
void init() {
  m["R"] = {0, 1};
  m["L"] = {0, -1};
  m["B"] = {-1, 0};
  m["T"] = {1, 0};
  m["RT"] = {1, 1};
  m["LT"] = {1, -1};
  m["RB"] = {-1, 1};
  m["LB"] = {-1, -1};
}
pii convert(string s) {
  int x = s[0] - 'A', y = s[1] - '1';
  return {y, x};
}
string convert(pii p) {
  char y = p.first + '1';
  char x = p.second + 'A';
  string ret;
  ret += x;
  ret += y;
  return ret;
}

void move(string str) {
  pii d = m[str];
  int ny = u.first + d.first;
  int nx = u.second + d.second;
  if (ny < 0 || ny > 7 || nx < 0 || nx > 7) return;
  if (v.first == ny && v.second == nx) {
    int nny = v.first + d.first;
    int nnx = v.second + d.second;
    if (nny < 0 || nny > 7 || nnx < 0 || nnx > 7) return;
    v = {nny, nnx};
    u = {ny, nx};
    return;
  }
  u = {ny, nx};
}

void solve() {
  init();
  u = convert(king);
  v = convert(dol);
  string str;
  while (n--) {
    cin >> str;
    move(str);
  }
  cout << convert(u) << "\n" << convert(v) << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> king >> dol >> n;
  solve();
}

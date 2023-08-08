#include <bits/stdc++.h>
using namespace std;

int n;
unordered_map<string, string> p;
unordered_map<string, int> h;

string find_root(string s1) {
  if (p[s1] == "") return s1;
  return find_root(p[s1]);
}

int union_root(string s1, string s2) {
  string u = find_root(s1);
  string v = find_root(s2);
  if (h[u] == 0) h[u] = 1;
  if (h[v] == 0) h[v] = 1;
  if (u == v) return h[u];
  if (h[u] < h[v]) swap(u, v);
  p[v] = u;
  h[u] += h[v];
  return h[u];
}

void solve() {
  p = unordered_map<string, string>();
  h = unordered_map<string, int>();

  cin >> n;

  string s1, s2;
  for (int i = 0; i < n; i++) {
    cin >> s1 >> s2;
    cout << union_root(s1, s2) << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}

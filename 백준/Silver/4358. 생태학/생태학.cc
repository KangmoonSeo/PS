#include <bits/stdc++.h>
using namespace std;
int len = 0;
map<string, int> m;

void solve() {
  for (auto it : m) {
    double ret = 100 * it.second / (double)len;
    cout << it.first << " " << fixed << setprecision(4) << ret << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  string str;
  while (getline(cin, str)) {
    m[str]++;
    len++;
  }
  solve();
}

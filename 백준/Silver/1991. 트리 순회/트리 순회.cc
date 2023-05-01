#include <bits/stdc++.h>
using namespace std;
map<char, pair<char, char> > a;
void t(char c, int i) {
  if (c == '.') return;
  if (i == 0) cout << c;
  t(a[c].first, i);
  if (i == 1) cout << c;
  t(a[c].second, i);
  if (i == 2) cout << c;
}
int main() {
  int n;
  cin >> n;
  char p;
  while (n--) cin >> p >> a[p].first >> a[p].second;
  for (int i = 0; i < 3; i++) {
    t('A', i);
    cout << "\n";
  }
}

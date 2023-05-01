#include <bits/stdc++.h>
using namespace std;

map<char, pair<char, char> > arr;

void traverse(char ch, int mode) {
  if (ch == '.') return;
  if (mode == 0) cout << ch;
  traverse(arr[ch].first, mode);
  if (mode == 1) cout << ch;
  traverse(arr[ch].second, mode);
  if (mode == 2) cout << ch;
}

void solve() {
  for (int i = 0; i < 3; i++) {
    traverse('A', i);
    cout << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  int n;  // input
  cin >> n;
  char c1, c2, c3;
  while (n--) {
    cin >> c1 >> c2 >> c3;
    arr[c1].first = c2;
    arr[c1].second = c3;
  }
  solve();
}

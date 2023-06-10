#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
  string str;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> str;
    int length = str.size();

    bool check[256] = {};
    bool isCorrect = true;
    char mem = '#';
    for (int j = 0; j < length; j++) {
      int c = str[j];
      if (check[c] && mem != str[j]) {
        isCorrect = false;
        break;
      }
      mem = c;
      check[c] = true;
    }
    if (isCorrect) ans++;
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n;
  solve();
}

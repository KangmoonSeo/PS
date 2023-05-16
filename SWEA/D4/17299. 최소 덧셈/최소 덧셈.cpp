#include <bits/stdc++.h>
using namespace std;

void solve() {
  string str;
  cin >> str;
  int length = str.length();
  int a, b, ans;
  if (length % 2 == 0) {
    a = stoi(str.substr(0, length / 2));
    b = stoi(str.substr(length / 2, length / 2));
    ans = a + b;
  } else {
    a = stoi(str.substr(0, length / 2));
    b = stoi(str.substr(length / 2, length / 2 + 1));
    ans = a + b;
    a = stoi(str.substr(0, length / 2 + 1));
    b = stoi(str.substr(length / 2 + 1, length / 2));
    ans = ans < a + b ? ans : a + b;
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cout << "#" << i << " ";
    solve();
  }
}

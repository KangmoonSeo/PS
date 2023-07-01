#include <bits/stdc++.h>
using namespace std;

string str;

void solve() {
  int type = 0;  // 1 : _, 2 : Upper
  int length = str.size();
  char mem = '0';
  string ans = "";
  for (int i = 0; i < length; i++) {
    if (str[i] == '_') {
      if (i == 0 || i == length - 1 || type == 2 || mem == '_') {
        cout << "Error!\n";
        return;
      }
      type = 1;
    }
    if (str[i] <= 'Z') {
      if (i == 0 || type == 1) {
        cout << "Error!\n";
        return;
      }
      type = 2;
    }
    if (type == 1 && mem == '_') {
      ans += (char)(str[i] + 'A' - 'a');
    } else if (type == 2 && str[i] <= 'Z') {
      ans += "_";
      ans += (char)(str[i] + 'a' - 'A');
    } else if (type == 1 && str[i] == '_') {
    } else {
      ans += str[i];
    }
    mem = str[i];
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> str;
  solve();
}

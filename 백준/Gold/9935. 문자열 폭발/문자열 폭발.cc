#include <bits/stdc++.h>
using namespace std;
string raw, pattern;

void solve() {
  int r_length = raw.size();
  const int p_length = pattern.size();

  string ans = "";
  for (int i = 0; i < r_length; i++) {
    ans += raw[i];
    int a_length = ans.size();
    if (ans[a_length - 1] == pattern[p_length - 1]) {
      bool isMatch = true;
      for (int j = 2; j <= p_length; j++) {
        if (ans[a_length - j] != pattern[p_length - j]) {
          isMatch = false;
        }
      }
      if (isMatch) {
        int k = p_length;
        while (k--) ans.pop_back();
      }
    }
  }

  if (ans == "") {
    cout << "FRULA\n";
  } else {
    cout << ans << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> raw >> pattern;
  solve();
}

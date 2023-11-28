#include <bits/stdc++.h>
using namespace std;

vector<string> vec;
vector<string> res;  // vec[0] + vec[1] + ... + vec[5]
vector<int> s;       // sequence
bool visited[6] = {};
void validate() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (vec[s[i]][j] != vec[s[j + 3]][i]) return;
    }
  }
  string ans = "";
  for (int i = 0; i < 6; i++) {
    ans += vec[s[i]];
  }
  res.push_back(ans);
}

void BT() {
  if (s.size() == 6) {
    validate();
    return;
  }

  for (int i = 0; i < 6; i++) {
    if (visited[i]) continue;
    visited[i] = true;
    s.push_back(i);
    BT();
    visited[i] = false;
    s.pop_back();
  }
}
void solve() {
  BT();
  if (res.empty()) {
    cout << "0\n";
    return;
  }
  string ans = res[0];
  for (int i = 1; i <= 9; i++) {
    cout << ans[i - 1];
    if (i % 3 == 0) cout << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  string str;
  for (int i = 0; i < 6; i++) {
    cin >> str;
    vec.push_back(str);
  }
  solve();
}

#include <bits/stdc++.h>
using namespace std;

int n;
int raw[51];
int rev[51];

vector<int> cmp;
vector<vector<int> > ans;

bool detect() {
  int tmp[101];
  for (int i = 0; i < n; i++) {
    tmp[i] = cmp[i];
    tmp[n + i] = cmp[i];
  }
  for (int i = 0; i < n; i++) {
    bool f_raw = true, f_rev = true, ret = true;
    for (int j = 0; j < n; j++) {
      f_raw &= tmp[j + i] == raw[j];
      f_rev &= tmp[j + i] == rev[j];
      if (f_raw || f_rev) continue;
      ret = false;
      break;
    }
    if (ret) return true;
  }
  return false;
}

void solve() {
  cmp = vector<int>(n);
  int m;
  cin >> m;
  while (m--) {
    for (int i = 0; i < n; i++) {
      cin >> cmp[i];
    }
    if (detect()) ans.push_back(cmp);
  }

  int length = ans.size();
  cout << length << "\n";
  for (int i = 0; i < length; i++) {
    for (int it : ans[i]) {
      cout << it << " ";
    }
    cout << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> raw[i];
    rev[n - 1 - i] = 1 + (raw[i] + 1) % 4;
  }
  solve();
}

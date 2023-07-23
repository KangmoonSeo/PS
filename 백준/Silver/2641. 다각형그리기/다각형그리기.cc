#include <bits/stdc++.h>
using namespace std;

int n, m, raw[51], rev[51];

vector<int> cmp;
vector<vector<int> > ans;

bool detect() {
  int tmp[101];  // cmp + cmp
  for (int i = 0; i < n; i++) {
    tmp[i] = cmp[i];
    tmp[n + i] = cmp[i];
  }

  for (int i = 0; i < n; i++) {
    bool isRaw = 1, isRev = 1, ret = 1;
    for (int j = 0; j < n; j++) {
      isRaw &= tmp[j + i] == raw[j];
      isRev &= tmp[j + i] == rev[j];
      if (isRaw || isRev) continue;
      ret = 0;
      break;
    }
    if (ret) return true;
  }
  return false;
}

void solve() {
  cin >> m;
  cmp = vector<int>(n);
  while (m--) {
    for (int i = 0; i < n; i++) {
      cin >> cmp[i];
    }
    if (detect()) ans.push_back(cmp);
  }

  int len = ans.size();
  cout << len << "\n";
  for (int i = 0; i < len; i++) {
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

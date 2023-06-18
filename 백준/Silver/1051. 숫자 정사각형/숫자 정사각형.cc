#include <bits/stdc++.h>
using namespace std;

int n, m, len;
vector<string> arr;

bool find() {
  for (int j = 0; j < n - len; j++) {
    for (int i = 0; i < m - len; i++) {
      char target = arr[j][i];
      if (target != arr[j + len][i]) continue;
      if (target != arr[j][i + len]) continue;
      if (target != arr[j + len][i + len]) continue;
      return true;
    }
  }
  len--;
  if (len <= 0)
    return true;
  else
    return false;
}

void solve() {
  len = min(n, m) - 1;
  while (true) {
    if (find()) break;
  }
  len++;
  cout << len * len << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n >> m;
  string input;
  for (int i = 0; i < n; i++) {
    cin >> input;
    arr.push_back(input);
  }

  solve();
}

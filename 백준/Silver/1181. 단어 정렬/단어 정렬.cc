#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
  vector<vector<string> > vec(51, vector<string>());
  string str;
  for (int i = 0; i < n; i++) {
    cin >> str;
    vec[str.size()].push_back(str);
  }
  for (int i = 1; i <= 50; i++) {
    if (vec[i].empty()) continue;
    sort(vec[i].begin(), vec[i].end());
    vec[i].erase(unique(vec[i].begin(), vec[i].end()), vec[i].end());
    for (auto it : vec[i]) {
      cout << it << "\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n;
  solve();
}

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n;
pii vec[100001];
bool cmp(pii a, pii b) {
  return (a.second != b.second) ? a.second < b.second : a.first < b.first;
}

void solve() {
  int xx, yy;

  for (int i = 0; i < n; i++) {
    cin >> xx >> yy;
    vec[i] = {xx, yy};
  }

  sort(vec, vec + n, cmp);

  for (int i = 0; i < n; i++) {
    cout << vec[i].first << " " << vec[i].second << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n;
  solve();
}

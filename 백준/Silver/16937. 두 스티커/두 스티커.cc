#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
int h, w, n;

struct CMP {
  bool operator()(pipii a, pipii b) {
    return (a.first != b.first) ? (a.first > b.first)
                                : (a.second.first > b.second.first);
  }
} cmp;
vector<pipii> vec;
int loops[4][4] = {{1, 1, 2, 2}, {1, 2, 2, 1}, {2, 1, 1, 2}, {2, 2, 1, 1}};

void solve() {
  sort(vec.begin(), vec.end(), cmp);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int ii[3] = {vec[i].first, vec[i].second.first, vec[i].second.second};

    if (ii[1] > h || ii[2] > w) continue;
    for (int j = i + 1; j < n; j++) {
      int jj[3] = {vec[j].first, vec[j].second.first, vec[j].second.second};

      bool fl = false;
      for (auto it : loops) {
        int x = max(ii[it[0]], jj[it[1]]);
        int y = ii[it[2]] + jj[it[3]];
        if (x <= h && y <= w || y <= h && x <= w) {
          fl = true;
          break;
        }
      }
      if (fl) {
        ans = max(ans, ii[0] + jj[0]);
        break;
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> h >> w;
  if (h < w) swap(h, w);
  cin >> n;
  int a, b;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if (a < b) swap(a, b);
    vec.push_back({a * b, {a, b}});
  }
  solve();
}

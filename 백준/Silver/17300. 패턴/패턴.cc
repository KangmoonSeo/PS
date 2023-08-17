#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n;
bool visited[10] = {};
vector<pair<pii, int> > vec;

void make_vec() {
  vec.push_back({{1, 3}, 2}), vec.push_back({{1, 7}, 4});
  vec.push_back({{1, 9}, 5}), vec.push_back({{2, 8}, 5});
  vec.push_back({{3, 7}, 5}), vec.push_back({{4, 6}, 5});
  vec.push_back({{3, 9}, 6}), vec.push_back({{7, 9}, 8});
}
bool check(int u, int v) {
  if (u > v) swap(u, v);
  for (auto it : vec) {
    pii p = it.first;
    if (p.first == u && p.second == v && !visited[it.second]) return false;
  }
  return true;
}
void solve() {
  make_vec();
  bool ans = true;
  int x, mem = 0;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (visited[x]) ans = false;
    if (!check(mem, x)) ans = false;
    visited[x] = true;
    mem = x;
  }
  cout << (ans ? "YES\n" : "NO\n");
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n;
  solve();
}

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n;
bool visited[10] = {};
vector<pii> vec;

void init() {
  vec.push_back({1, 3}), vec.push_back({1, 7});
  vec.push_back({1, 9}), vec.push_back({2, 8});
  vec.push_back({3, 7}), vec.push_back({4, 6});
  vec.push_back({3, 9}), vec.push_back({7, 9});
}

bool check(int u, int v) {
  if (u > v) swap(u, v);
  for (pii p : vec) {
    if (p.first == u && p.second == v && !visited[(p.first + p.second) / 2])
      return false;
  }
  return true;
}

void solve() {
  init();
  bool ans = true;
  int x, mem = 0;
  while (n--) {
    cin >> x;
    if (visited[x] || !check(mem, x)) ans = false;
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

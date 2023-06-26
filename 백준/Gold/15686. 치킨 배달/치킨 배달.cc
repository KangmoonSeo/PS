#include <bits/stdc++.h>
using namespace std;
#define y first
#define x second
typedef pair<int, int> pii;

int n, m;
vector<pii> store;
vector<vector<int> > candidates;
vector<pii> home;

vector<int> bt;
void BT(int init = 0, int TTL = 0) {
  if (TTL == m) {
    candidates.push_back(bt);
    return;
  }
  for (int i = init; i < store.size(); i++) {
    bt.push_back(i);
    BT(i + 1, TTL + 1);
    bt.pop_back();
  }
}

void solve() {
  int ans = 1e9;
  BT();
  for (int i = 0; i < candidates.size(); i++) {
    int sum = 0;
    for (int j = 0; j < home.size(); j++) {
      pii p_home = home[j];
      int min_home = 1e9;
      for (int k = 0; k < candidates[i].size(); k++) {
        pii p_store = store[candidates[i][k]];
        min_home = min(min_home,
                       abs(p_store.y - p_home.y) + abs(p_store.x - p_home.x));
      }
      sum += min_home;
    }
    ans = min(ans, sum);
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n >> m;
  int input;
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= n; i++) {
      cin >> input;
      if (input == 1) home.push_back({j, i});
      if (input == 2) store.push_back({j, i});
    }
  }
  solve();
}

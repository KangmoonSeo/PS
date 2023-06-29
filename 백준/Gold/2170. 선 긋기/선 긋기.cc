#include <bits/stdc++.h>
#define u first
#define v second
using namespace std;
typedef pair<int, int> pii;
int n;

vector<pii> vec;
void solve() {
  sort(vec.begin(), vec.end());  // O(NlogN)
  int ans = 0;
  pii p = vec[0];
  int init = p.u;
  int mem = p.v;
  for (int i = 1; i < n; i++) {  // O(N)
    p = vec[i];
    // add length
    if (mem < p.u) {
      ans += mem - init;
      init = p.u;
    }
    mem = max(mem, p.v);
  }
  ans += mem - init;
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n;
  int x, y;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    vec.push_back({x, y});
  }
  solve();
}

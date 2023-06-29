#include <bits/stdc++.h>
#define u first
#define v second
using namespace std;
typedef pair<int, int> pii;
int n;
pii arr[1000001];

void solve() {
  sort(arr, arr + n);  // O(NlogN)
  int ans = 0;
  pii p = arr[0];
  int init = p.u;
  int mem = p.v;
  for (int i = 1; i < n; i++) {  // O(N)
    p = arr[i];
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
    arr[i] = {x, y};
  }
  solve();
}

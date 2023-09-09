#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define dir first
#define dist second
pii cur;
int w, h, n;
vector<pii> vec;

pii convert(pii prev) {  // convert { dir, dist } to { y, x }
  pii ret;
  switch (prev.dir) {
    case 1:
      ret = {0, prev.dist};
      break;
    case 2:
      ret = {h, prev.dist};
      break;
    case 3:
      ret = {prev.dist, 0};
      break;
    case 4:
      ret = {prev.dist, w};
      break;
  }
  return ret;
}

void solve() {
  int ans = 0;

  for (pii p : vec) {
    int dy = abs(cur.first - p.first);
    int dx = abs(cur.second - p.second);
    ans += dy + dx;
    if (dy == h && dx != w) {
      ans += 2 * min({cur.second, p.second, w - cur.second, w - p.second});
    } else if (dy != h && dx == w) {
      ans += 2 * min({cur.first, p.first, h - cur.first, h - p.first});
    }
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> w >> h;
  cin >> n;
  pii input;
  for (int i = 0; i < n; i++) {
    cin >> input.dir >> input.dist;
    vec.push_back(convert(input));
  }
  cin >> input.dir >> input.dist;
  cur = convert(input);

  solve();
}

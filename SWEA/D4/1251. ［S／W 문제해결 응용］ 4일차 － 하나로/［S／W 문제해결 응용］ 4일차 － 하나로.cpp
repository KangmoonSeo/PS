#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int n;
pii P[1001];  // {x, y}
long double E;
vector<pair<long long, pii>> vec;  // {w, {u, v}}
int p[1001];
int h[1001];

int find_root(int u) {
  if (p[u] == -1) return u;
  p[u] = find_root(p[u]);
  return p[u];
}

bool union_root(int u, int v) {
  u = find_root(u);
  v = find_root(v);
  if (u == v) return true;
  if (h[u] > h[v]) swap(u, v);
  p[u] = v;
  if (h[u] == h[v]) h[v]++;
  return false;
}

void init() {
  vec = vector<pair<ll, pii>>();
  fill_n(p, n + 1, -1);
  fill_n(h, n + 1, 0);
}

ll solve() {
  cin >> n;
  init();

  for (int i = 1; i <= n; i++) {
    cin >> P[i].first;
  }
  for (int i = 1; i <= n; i++) {
    cin >> P[i].second;
  }
  cin >> E;

  for (int u = 1; u <= n; u++) {
    for (int v = 1; v < u; v++) {
      ll dx = P[u].first - P[v].first;
      ll dy = P[u].second - P[v].second;
      ll w = (dx * dx + dy * dy);
      vec.push_back({w, {u, v}});
    }
  }

  sort(vec.begin(), vec.end());

  long double ans = 0.0;
  int cnt = 0;
  int len = vec.size();
  for (int i = 0; i < len; i++) {
    ll w = vec[i].first;
    int u = vec[i].second.first;
    int v = vec[i].second.second;

    if (union_root(u, v)) continue;
    ans += w;
    cnt++;
    if (cnt >= n - 1) break;
  }

  ll ret = round(E * ans);
  return ret;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  int T;
  cin >> T;

  for (int i = 1; i <= T; i++) {
    ll ret = solve();
    cout << "#" << i << " " << ret << "\n";
  }
}

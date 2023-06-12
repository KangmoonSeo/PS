#include <bits/stdc++.h>
#define y first
#define x second
using namespace std;
typedef pair<double, double> pdd;
pdd P[101];
vector<pair<double, pair<int, int> > > vec;  // weight, u, v
int n;
int p[101];
int h[101] = {};
int find_root(int u) {
  if (p[u] == -1) return u;
  p[u] = find_root(p[u]);
  return p[u];
}
bool union_root(int u, int v) {
  u = find_root(u);
  v = find_root(v);
  if (u == v) return true;  // it is same tree
  if (h[u] > h[v]) swap(u, v);
  p[u] = v;
  if (h[u] == h[v]) h[v]++;
  return false;  // union completed
}

double getWeight(pdd a, pdd b) {
  double ret = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
  ret = sqrt(ret);
  return ret;
}
void solve() {
  fill_n(p, 101, -1);
  sort(vec.begin(), vec.end());
  double ans = 0;
  int cnt = 0;
  for (int i = 0; i < vec.size(); i++) {
    double w = vec[i].first;
    int u = vec[i].second.first;
    int v = vec[i].second.second;
    if (union_root(u, v)) continue;
    ans += w;
    cnt++;
    if (cnt >= n - 1) break;
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n;
  double xx, yy;
  for (int i = 0; i < n; i++) {
    cin >> xx >> yy;
    P[i] = make_pair(yy, xx);
    for (int j = 0; j < i; j++) {
      double w = getWeight(P[i], P[j]);
      vec.push_back(make_pair(w, make_pair(i, j)));
    }
  }

  solve();
}

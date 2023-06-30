#include <bits/stdc++.h>
using namespace std;
typedef pair<int, string> pis;
int n;
vector<pis> vec;

bool cmp(pis a, pis b) { return a.first < b.first; }
void solve() {
  int a;
  string b;
  for (size_t i = 0; i < n; i++) {
    cin >> a >> b;
    vec.push_back({a, b});
  }

  stable_sort(vec.begin(), vec.end(), cmp);
  for (int i = 0; i < n; i++) {
    cout << vec[i].first << " " << vec[i].second << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n;
  solve();
}

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n;
vector<pii> vec;

bool cmp(pii a, pii b) {
  return a.first != b.first ? a.first < b.first : a.second > b.second;
}

void solve() {
  sort(vec.begin(), vec.end(), cmp);
  vec.erase(unique(vec.begin(), vec.end()), vec.end());

  vector<int> seq;

  for (pii p : vec) {
    int v = -p.second;
    if (seq.empty() || seq.back() <= v) {
      seq.push_back(v);
    } else {
      int prev = upper_bound(seq.begin(), seq.end(), v) - seq.begin();
      seq[prev] = v;
    }
  }
  cout << seq.size() << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n;
  int hmm, u, v;
  for (int i = 0; i < n; i++) {
    cin >> hmm >> u >> v;
    vec.push_back({u, v});
  }

  solve();
}

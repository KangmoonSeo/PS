#include <bits/stdc++.h>
#define weight first
#define value second
using namespace std;
int n, k;

void solve() {
  vector<pair<int, int> > vec(n);
  int i1, i2;
  for (int i = 0; i < n; i++) {
    cin >> i1 >> i2;
    vec[i] = make_pair(i1, i2);
  }

  vector<vector<int> > P(n + 1, vector<int>(k + 1));
  for (int i = 1; i <= n; i++) {
    pair<int, int> p = vec[i - 1];

    for (int w = 1; w <= k; w++) {
      if (w - p.weight >= 0) {
        P[i][w] = max(P[i - 1][w], p.value + P[i - 1][w - p.weight]);
      } else {
        P[i][w] = P[i - 1][w];
      }
    }
  }
  cout << P[n][k] << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n >> k;
  solve();
}

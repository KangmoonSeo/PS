#include <bits/stdc++.h>
#define weight first
#define value second
using namespace std;
int n, k;

void solve() {
  vector<vector<int> > P(n + 1, vector<int>(k + 1));
  int wei, val;
  for (int i = 1; i <= n; i++) {
    cin >> wei >> val;
    for (int w = k; w >= 1; w--) {
      if (w - wei >= 0) {
        P[i][w] = max(P[i - 1][w], val + P[i - 1][w - wei]);
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

#include <bits/stdc++.h>
using namespace std;

#define MAX_ 1e8
#define min(a, b) a > b ? b : a;

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  int D[101][101];
  int N[101][101];
  int n, m, i1, i2, i3;
  cin >> n >> m;

  fill(&D[0][0], &D[100][101], MAX_);
  for (int i = 1; i <= n; i++) D[i][i] = 0;

  while (m--) {
    cin >> i1 >> i2 >> i3;
    D[i1][i2] = min(D[i1][i2], i3);
    N[i1][i2] = i2;
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (i == j) continue;
        if (D[i][j] > D[i][k] + D[k][j]) {
          D[i][j] = D[i][k] + D[k][j];
          N[i][j] = N[i][k];
        }
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (D[i][j] == MAX_)
        cout << "0 ";
      else
        cout << D[i][j] << " ";
    }
    cout << "\n";
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (D[i][j] == MAX_ || D[i][j] == 0) {
        cout << "0\n";
        continue;
      }
      vector<int> v;
      int cur = i;
      while (cur != j) {
        v.push_back(cur);
        cur = N[cur][j];
      }
      v.push_back(cur);
      cout << v.size() << " ";
      for (int x : v) cout << x << " ";
      cout << "\n";
    }
  }
}

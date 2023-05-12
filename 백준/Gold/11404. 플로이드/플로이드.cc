#include <bits/stdc++.h>
using namespace std;

#define MAX_ 1e9
#define min(a, b) a > b ? b : a;

int D[101][101];
int n;

void print() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (D[i][j] == MAX_)
        cout << "0 ";
      else
        cout << D[i][j] << " ";
    }
    cout << "\n";
  }
}

void floid() {
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (i == j) continue;
        D[i][j] = min(D[i][j], D[i][k] + D[k][j]);  // floid
      }
    }
  }
}

void solve() {
  floid();
  print();
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  int m, i1, i2, i3;
  cin >> n >> m;

  fill(&D[0][0], &D[100][101], MAX_);
  while (m--) {
    cin >> i1 >> i2 >> i3;
    D[i1][i2] = min(D[i1][i2], i3);
  }
  solve();
}

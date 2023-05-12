#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int> > vvi;
#define MAX_ 1e9
#define min(a, b) a > b ? b : a;

int D[101][101];
int n;

void add(int a, int b, int n = 1) {
  D[a][b] = n;
  D[b][a] = n;
}

void floid() {
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        D[i][j] = min(D[i][j], D[i][k] + D[k][j]);  // floid
      }
    }
  }
}

void calcBacon() {
  int p_sum = MAX_;
  int p = 0;
  for (int k = 1; k <= n; k++) {
    int sum = 0;
    for (int j = 1; j <= n; j++) {
      if (k == j) continue;
      sum += D[k][j];
    }
    if (p_sum > sum) {
      p_sum = sum;
      p = k;
    }
  }
  cout << p << "\n";
}

void solve() {
  floid();
  calcBacon();
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  int m;
  cin >> n >> m;

  int i1, i2;
  fill(&D[0][0], &D[100][101], MAX_);

  while (m--) {
    cin >> i1 >> i2;
    add(i1, i2);
  }
  solve();
}

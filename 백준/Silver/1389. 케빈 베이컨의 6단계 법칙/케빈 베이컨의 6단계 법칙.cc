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

void print() {
  for (int i = 1; i <= n; i++) {
    cout << "|";
    for (int j = 1; j <= n; j++) {
      cout << D[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
}

void floid() {
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
      }
    }
  }
}

int calcBacon() {
  int ans = MAX_;
  int p;
  for (int k = 1; k <= n; k++) {
    int sum = 0;
    for (int j = 1; j <= n; j++) {
      if (k == j) continue;
      sum += D[k][j];
    }
    if (ans > sum) {
      ans = sum;
      p = k;
    }
  }
  return p;
}
void bacon() {
  floid();
  int ans = calcBacon();
  cout << ans << "\n";
}

int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 실행속도 최적화 end
  int m;
  cin >> n >> m;

  int i1, i2;
  fill(&D[0][0], &D[100][101], MAX_);

  while (m--) {
    cin >> i1 >> i2;
    add(i1, i2);
  }
  bacon();
}

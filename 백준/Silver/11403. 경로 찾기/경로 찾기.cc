#include <bits/stdc++.h>
#define min(a, b) a > b ? b : a
using namespace std;

int n;

void solve() {
  vector<vector<int> > arr(101, vector<int>(101, 1e6));
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= n; i++) {
      cin >> arr[j][i];
      if (arr[j][i] == 0) arr[j][i] = 1e6;
    }
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
      }
    }
  }
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= n; i++) {
      if (arr[j][i] >= 1e6)
        cout << "0 ";
      else
        cout << "1 ";
    }
    cout << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n;
  solve();
}

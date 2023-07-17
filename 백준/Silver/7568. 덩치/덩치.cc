#include <bits/stdc++.h>
using namespace std;

int n, cm[50], kg[50];

void solve() {
  for (int i = 0; i < n; i++) {
    int cnt = 1;
    for (int j = 0; j < n; j++) {
      if (cm[i] < cm[j] && kg[i] < kg[j]) cnt++;
    }
    cout << cnt << " ";
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> cm[i] >> kg[i];
  }

  solve();
}

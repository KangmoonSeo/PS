#include <bits/stdc++.h>
using namespace std;

int n;

void recur(int x, int y, int num) {
  if ((x / num) % 3 == 1 && (y / num) % 3 == 1) {
    cout << " ";
  } else if (num / 3 == 0) {
    cout << "*";
  } else {
    recur(x, y, num / 3);
  }
}
void solve() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      recur(i, j, n);
    }
    cout << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n;
  solve();
}

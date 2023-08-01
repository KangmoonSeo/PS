#include <bits/stdc++.h>
using namespace std;

unsigned int x[3], y[3], ans = 0;

void eat() {
  for (int i = 0; i < 3; i++) {
    bool fl = x[i] > y[i];
    if (fl) swap(x[i], y[i]);
    ans += x[i];
    y[i] -= x[i];
    x[i] = 0;
    if (fl) swap(x[i], y[i]);
    y[i] /= 3;
  }
}
void exchange() {
  swap(y[0], y[1]);
  swap(y[0], y[2]);
}
void solve() {
  for (int i = 0; i < 3; i++) {
    eat();
    exchange();
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  for (int i = 0; i < 3; i++) cin >> x[i];
  for (int i = 0; i < 3; i++) cin >> y[i];
  solve();
}

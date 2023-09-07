#include <bits/stdc++.h>
using namespace std;
/*
const int dy[4] = {-2, -1, 1, 2};
const int dx[4] = {1, 2, 2, 1};
*/
int n, m;

void solve() {
  if (n == 1)
    cout << 1;
  else if (n == 2)
    cout << min(4, (m + 1) / 2);
  else if (m < 7)
    cout << min(4, m);
  else
    cout << m - 2;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n >> m;
  solve();
}

#include <bits/stdc++.h>
using namespace std;

int n, m;

void BT(string str = "", int TTL = 0) {
  if (TTL == m) {
    cout << str << "\n";
    return;
  }
  for (int i = 1; i <= n; i++) {
    BT(str + to_string(i) + " ", TTL + 1);
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n >> m;
  BT();
}

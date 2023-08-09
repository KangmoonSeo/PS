#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<int> bt;
void BT(int TTL = 0) {
  if (TTL == m) {
    for (int it : bt) {
      cout << it << " ";
    }
    cout << "\n";
    return;
  }
  for (int i = 1; i <= n; i++) {
    bt.push_back(i);
    BT(TTL + 1);
    bt.pop_back();
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n >> m;
  BT();
}

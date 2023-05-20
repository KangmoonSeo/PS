#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<bool> bt(9);
vector<int> ans;
void BT(int TTL = 0) {
  if (TTL == m) {
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << " ";
    }
    cout << "\n";
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (bt[i]) continue;
    bt[i] = true;
    ans.push_back(i);
    BT(TTL + 1);
    bt[i] = false;
    ans.pop_back();
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n >> m;
  BT();
}

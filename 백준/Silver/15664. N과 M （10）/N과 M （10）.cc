#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> arr;
vector<int> bt;
set<vector<int> > ans;

void BT(int TTL = 0, int init = 0) {
  if (m == TTL) {
    ans.insert(bt);
    return;
  }
  for (int i = init; i < n; i++) {
    bt.push_back(arr[i]);
    BT(TTL + 1, i + 1);
    bt.pop_back();
  }
}
void solve() {
  int input;
  // input
  for (int i = 0; i < n; i++) {
    cin >> input;
    arr.push_back(input);
  }
  // calculate
  sort(arr.begin(), arr.end());
  BT();
  // output
  for (auto it : ans) {
    for (int i = 0; i < m; i++) {
      cout << it[i] << " ";
    }
    cout << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n >> m;
  solve();
}

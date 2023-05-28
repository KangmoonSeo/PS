#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> arr;
vector<int> bt;
bool visited[8] = {};

void BT(int TTL = 0) {
  if (m == TTL) {
    for (int i = 0; i < m; i++) {
      cout << bt[i] << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      bt.push_back(arr[i]);
      visited[i] = true;
      BT(TTL + 1);
      bt.pop_back();
      visited[i] = false;
    }
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization
  int input;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> input;
    arr.push_back(input);
  }
  sort(arr.begin(), arr.end());

  BT();
}

#include <bits/stdc++.h>
using namespace std;

int n, m, arr[8];
bool visited[8] = {};
vector<int> bt;

void BT(int TTL = 0, int init = 0) {
  if (TTL == m) {
    for (int i = 0; i < m; i++) {
      cout << bt[i] << " ";
    }
    cout << "\n";
    return;
  }

  int pre = 0;  // TTL 단계의 memory
  for (int i = 0; i < n; i++) {
    if (pre != arr[i] && !visited[i]) {
      pre = arr[i];
      bt.push_back(arr[i]);
      visited[i] = true;
      BT(TTL + 1, i + 1);
      visited[i] = false;
      bt.pop_back();
    }
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  BT();
}

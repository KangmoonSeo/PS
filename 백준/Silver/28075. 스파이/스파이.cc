#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, m;  // n:총 일수, m:얻고 싶은 최소 기여도

int arr[2][3];
int cnt;

void BT(int TTL, int res, int x) {
  if (TTL >= n) {
    if (res >= m) cnt++;
    return;
  }
  for (int j = 0; j < 2; j++) {
    for (int i = 0; i < 3; i++) {
      int val = res;
      if (x == i) {
        val += arr[j][i] / 2;
      } else {
        val += arr[j][i];
      }
      BT(TTL + 1, val, i);
    }
  }
}

void solve() {
  cnt = 0;
  cin >> n >> m;
  for (int j = 0; j < 2; j++) {
    for (int i = 0; i < 3; i++) {
      cin >> arr[j][i];
    }
  }
  for (int j = 0; j < 2; j++) {
    for (int i = 0; i < 3; i++) {
      BT(1, arr[j][i], i);
    }
  }
  cout << cnt << "\n";
}
int main() {
  //
  solve();
}
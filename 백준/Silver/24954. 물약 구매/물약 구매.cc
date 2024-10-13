#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> c(11);  // original potion costs, [1, 1000]
int arr[11][11];    // u -> v 할인표
int ans = 1e9;
int cnt = 0;

bool visited[11];

/**
 * @param
 * vec : 현재 포션 가격표
 * TTL : 종료 시간
 */
void BT(vector<int> vec, int TTL) {
  if (TTL == n) {
    ans = ans > cnt ? cnt : ans;
    return;
  }

  for (int i = 1; i <= n; i++) {
    if (visited[i]) continue;
    visited[i] = true;
    vector<int> new_vec(11);

    cnt += vec[i];
    for (int v = 1; v <= n; v++) {
      new_vec[v] = vec[v] - arr[i][v];
      new_vec[v] = new_vec[v] > 1 ? new_vec[v] : 1;
    }

    BT(new_vec, TTL + 1);
    cnt -= vec[i];
    visited[i] = false;
  }
}

void solve() {
  // original potion costs
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }

  // 물약 할인 정보
  for (int u = 1; u <= n; u++) {
    int p;
    cin >> p;
    while (p--) {
      int v, d;
      cin >> v >> d;
      arr[u][v] = d;  // u 샀을 때 v가 d만큼 할인
    }
  }
  BT(c, 0);
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n;
  solve();
  cout << ans << "\n";
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
ll arr[10001];
/**
 * N:명의 아이들이 한 줄로 줄을 서서 놀이기구를 기다리고 있음.
 *
 * M:종류의 1인승 놀이기구가 있으며,
 * 1번부터 M번까지 번호가 매겨져 있음., m in [1, 10000]
 *
 * arr_i: i번째 놀이기구의 운행 시간, arr_i in [1, 30]
 *
 * all_time: 전체 놀이기구의 운행 시간, all_time in [1, 60,000,000,000]
 *
 * 1st: 작은 번호에 먼저 탑승
 *
 *
 * @returns
 * (int): 줄의 마지막 아이가 타게 되는 놀이기구의 번호
 *
 * sol1) m개 놀이기구의 최대공약 사이클?
 *     운이 좋지 않다면, time_cycle = 30!
 */

bool condition(ll val_time) {
  // val_time에 n명이 놀이기구를 다 탈 수 있는가?
  ll cnt = 0;
  for (int i = 0; i < m; i++) {
    cnt += val_time / arr[i];
    if (cnt >= n) return true;
  }
  return false;
}

ll bsearch(ll l, ll r) {
  if (l == r) return l;
  ll mid = (l + r) / 2;
  //
  if (condition(mid)) {
    // val_time에 다 탈 수 있음 -> val_time 줄여보기
    return bsearch(l, mid);
  } else {
    // val_time에 다 탈 수 없음
    return bsearch(mid + 1, r);
  }
}
int solve() {
  // function works here
  //
  for (int i = 0; i < m; i++) {
    cin >> arr[i];
  }
  if (n <= m) {
    return n;
  }
  // 0. 0분에는 다 탐
  n -= m;

  // 1. get all_time
  ll min_time = 1;
  ll max_time = 2e18;
  ll all_time = bsearch(min_time, max_time);

  // 10 5 3 2 2

  /**
   * n=22, m=5
   * t|1 2 3 4 5
   * -------------
   * 0 x x x x x | 5
   * 1 x - - - - | 6
   * 2 x x - - - | 8
   * 3 x - x - - | 10
   * 4 x x - x - | 13
   * 5 x - - - x | 16
   * 6 x x x - - | 18
   * 7 x - - - - | 19
   * 8 x x - x - | 22
   */
  /**
   * n=24, m=5
   * t|1 2 2 4 4
   * -------------
   * 0 x x x x x | 5
   * 1 x - - - - | 6
   * 2 x x x - - | 9
   * 3 x - - - - | 10
   * 4 x x x x x | 15
   * 5 x - - - - | 16
   * 6 x x x - - | 19
   * 7 x - - - - | 20
   * 8 x x x x|x | 25 (24 fin)
   */

  int ans = -1;
  int cnt = 0;
  // t == 0
  cnt += m;

  // t in [1, all_time - 1]
  for (int i = 0; i < m; i++) {
    cnt += (all_time - 1) / arr[i];
  }

  // t == all_time
  for (int i = 0; i < m; i++) {
    if (all_time % arr[i] == 0) {
      cnt++;
      ans = i + 1;
      if (cnt == (n + m)) {
        break;
      }
    }
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n >> m;
  auto ans = solve();
  cout << ans << "\n";
}

#include <bits/stdc++.h>
using namespace std;

/**
 * 누진 전기요금
 *
 * 2: [1,100]
 * 3: (100,10000]
 * 5: (10000,1000000]
 * 7: (1000000, ~]
 *
 * ===
 * a: 이웃 사용량 + 내 사용량을 반영한 전기 요금, 회사의 간악한 수식
 * b: 이웃과 내가 쪼개서 납부했을 때, 나와 이웃의 전기 요금 차이
 *
 * @returns
 * 상근이가 내야 하는 전기 요금
 */

int a, b;

int calculate_watt(int cost) {
  int watt = 0;
  const int CEIL_1e2 = 2 * 1e2;
  const int CEIL_1e4 = 3 * (1e4 - 1e2) + CEIL_1e2;
  const int CEIL_1e6 = 5 * (1e6 - 1e4) + CEIL_1e4;

  if (cost <= CEIL_1e2) {
    // 2: [1,100]
    watt = 0;
    watt += cost / 2;

  } else if (cost <= CEIL_1e4) {
    // 3: (100,10000]
    watt = 1e2;
    watt += (cost - CEIL_1e2) / 3;

  } else if (cost <= CEIL_1e6) {
    // 5: (10000,1000000]
    watt = 1e4;
    watt += (cost - CEIL_1e4) / 5;
  } else {
    // 7: (1000000, ]
    watt = 1e6;
    watt += (cost - CEIL_1e6) / 7;
  }
  return watt;
}

int calculate_cost(int watt) {
  int cost = 0;

  if (watt < 1e2) {
    // 2: [1,100]
    cost = 2 * (watt - 0);
  } else if (watt < 1e4) {
    // 3: (100,10000]
    cost = 3 * (watt - 1e2) + 2 * (1e2);
  } else if (watt < 1e6) {
    // 5: (10000,1000000]
    cost = 5 * (watt - 1e4) + 3 * (1e4 - 1e2) + 2 * (1e2);
  } else {
    // 7: (1000000, ]
    cost = 7 * (watt - 1e6) + 5 * (1e6 - 1e4) + 3 * (1e4 - 1e2) + 2 * (1e2);
  }

  return cost;
}

int bsearch(int l_watt, int r_watt, int total_watt) {
  int mid_watt = (l_watt + r_watt) / 2;

  int my_cost = calculate_cost(mid_watt);
  int your_cost = calculate_cost(total_watt - mid_watt);
  int delta_cost = your_cost - my_cost;

  if (delta_cost == b) {
    return my_cost;
  }
  if (l_watt == r_watt) {
    return 0;
  }

  if (delta_cost > b) {
    return bsearch(mid_watt + 1, r_watt, total_watt);
  } else {
    return bsearch(l_watt, mid_watt - 1, total_watt);
  }
}

int solve() {
  // function works here
  int total_watt = calculate_watt(a);
  int ans = bsearch(0, total_watt, total_watt);

  return ans;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  while (true) {
    cin >> a >> b;
    if (a == 0 && b == 0) break;
    int ans = solve();
    cout << ans << "\n";
  }
}

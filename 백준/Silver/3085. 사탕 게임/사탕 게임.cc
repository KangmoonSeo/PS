#include <bits/stdc++.h>
using namespace std;

int n;
char arr[52][52];

int find_max_sequence() {
  int cnt = 0;
  for (int k = 1; k <= n; k++) {
    char mem_color = 0;
    int mem_cnt = 0;
    // V
    for (int j = 1; j <= n; j++) {
      if (arr[j][k] == mem_color) {
        mem_cnt++;
      } else {
        mem_color = arr[j][k];
        cnt = max(cnt, mem_cnt);
        mem_cnt = 1;
      }
    }
    cnt = max(cnt, mem_cnt);
    mem_cnt = 0;
    mem_color = 0;
    // -->
    for (int i = 1; i <= n; i++) {
      if (arr[k][i] == mem_color) {
        mem_cnt++;
      } else {
        mem_color = arr[k][i];
        cnt = max(cnt, mem_cnt);
        mem_cnt = 1;
      }
    }
    cnt = max(cnt, mem_cnt);
  }
  return cnt;
}

/**
 * n: 보드의 크기
 * arr: 보드에 채워져 있는 사탕의 색상
 *
 * @returns
 * (int): 상근이가 먹을 수 있는 사탕의 최대 개수
 */
int solve() {
  // function works here
  string input;
  for (int j = 1; j <= n; j++) {
    cin >> input;
    for (int i = 1; i <= n; i++) {
      arr[j][i] = input[i - 1];
    }
  }

  int cnt = 0;

  for (int k = 1; k <= n; k++) {
    for (int j = 1; j < n; j++) {
      if (arr[j][k] == arr[j + 1][k]) continue;
      swap(arr[j][k], arr[j + 1][k]);
      cnt = max(cnt, find_max_sequence());
      swap(arr[j][k], arr[j + 1][k]);
    }
    for (int i = 1; i < n; i++) {
      if (arr[k][i] == arr[k][i + 1]) continue;
      swap(arr[k][i], arr[k][i + 1]);
      cnt = max(cnt, find_max_sequence());
      swap(arr[k][i], arr[k][i + 1]);
    }
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n;
  auto ans = solve();
  cout << ans << "\n";
}

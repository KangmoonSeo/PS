#include <bits/stdc++.h>
using namespace std;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int n, k, l;
int arr[102][102];
int moves[10001];  // L = -1, D = 1, straight = 0

int head_y, head_x;
int dir;

/**
 * -1: 사과
 * 0: 빈칸
 * 1~10000: 뱀의 몸
 * -1e9: 벽
 */

void lose_weight() {
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= n; i++) {
      if (arr[j][i] > 0) arr[j][i]--;
    }
  }
}

void solve() {
  fill_n(arr[0], 102 * 102, 1e8);
  fill_n(moves, 10001, 0);

  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= n; i++) {
      arr[j][i] = 0;
    }
  }
  head_y = 1, head_x = 1, dir = 0;
  arr[head_y][head_x] = 1;

  //
  cin >> k;  // 사과의 개수
  for (int i = 0; i < k; i++) {
    int yy, xx;
    cin >> yy >> xx;
    arr[yy][xx] = -1;
  }

  cin >> l;  // 방향 변환 정보
  for (int i = 0; i < l; i++) {
    int xx;
    char cc;  // ['L', 'D']
    cin >> xx >> cc;
    if (cc == 'L') {
      moves[xx] = -1;
    } else {
      moves[xx] = 1;
    }
  }
  //
  for (int i = 1; i <= 10000; i++) {
    // check next head
    int nxt_y = head_y + dy[dir];
    int nxt_x = head_x + dx[dir];

    if (arr[nxt_y][nxt_x] == -1) {  // 사과

      arr[nxt_y][nxt_x] = arr[head_y][head_x] + 1;
      head_y = nxt_y;
      head_x = nxt_x;

    } else if (arr[nxt_y][nxt_x] == 0) {  // 빈 공간

      arr[nxt_y][nxt_x] = arr[head_y][head_x] + 1;
      head_y = nxt_y;
      head_x = nxt_x;
      lose_weight();

    } else {  // 충돌; 벽 또는 몸
      cout << i << "\n";
      return;
    }
    // set next direction
    dir = (dir + moves[i] + 4) % 4;
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n;
  solve();
}

#include <bits/stdc++.h>
using namespace std;

int r, c, n;
char arr[202][202] = {};
bool visited[202][202] = {};

const int dy[4] = {1, 0, -1, 0};
const int dx[4] = {0, 1, 0, -1};

void flake(int y, int x) {
  visited[y][x] = true;
  for (int i = 0; i < 4; i++) {
    int ny = dy[i] + y;
    int nx = dx[i] + x;
    visited[ny][nx] = true;
  }
}

void print() {
  bool isEven = n % 2 == 0;

  for (int j = 1; j <= r; j++) {
    for (int i = 1; i <= c; i++) {
      cout << (isEven ? 'O' : arr[j][i]);
    }
    cout << "\n";
  }
}
void solve() {
  for (int k = 3; k <= n; k += 2) {
    fill_n(visited[0], 202 * 202, false);

    for (int j = 1; j <= r; j++) {
      for (int i = 1; i <= c; i++) {
        if (arr[j][i] == 'O') flake(j, i);
      }
    }
    for (int j = 1; j <= r; j++) {
      for (int i = 1; i <= c; i++) {
        arr[j][i] = visited[j][i] ? '.' : 'O';
      }
    }
  }
  print();
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> r >> c >> n;
  string str;
  for (int j = 1; j <= r; j++) {
    cin >> str;
    for (int i = 1; i <= c; i++) {
      arr[j][i] = str[i - 1];
    }
  }

  solve();
}

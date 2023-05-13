#include <bits/stdc++.h>
using namespace std;

int graph[1001][1001];
string result;

int main() {
  int R, C;
  cin >> R >> C;
  pair<int, int> no;
  int minscore = 1e9;

  for (int y = 0; y < R; y++) {
    for (int x = 0; x < C; x++) {
      cin >> graph[y][x];
      if ((y + x) % 2 && minscore > graph[y][x]) {
        minscore = graph[y][x];
        no = make_pair(y, x);
      }
    }
  }

  if (R % 2) {
    for (int y = 0; y < R; y++) {
      for (int x = 0; x < C - 1; x++)
        if (y % 2 == 0)
          result += 'R';
        else
          result += 'L';
      if (y != R - 1) result += 'D';
    }
  } else if (!(R % 2) && C % 2) {
    for (int x = 0; x < C; x++) {
      for (int y = 0; y < R - 1; y++)
        if (x % 2 == 0)
          result += 'D';
        else
          result += 'U';
      if (x != C - 1) result += 'R';
    }
  } else if (!(R % 2) && !(C % 2)) {
    int nR, nC;
    if (no.first % 2 == 1)
      nR = no.first - 1;
    else
      nR = no.first;
    for (int y = 0; y < nR; y++) {
      for (int x = 0; x < C - 1; x++) {
        if (y % 2 == 0)
          result += 'R';
        else
          result += 'L';
      }
      result += 'D';
    }
    nC = no.second;
    for (int x = 0; x < nC; x++) {
      if (x % 2 == 0)
        result += "DR";
      else
        result += "UR";
    }
    for (int x = nC; x < C - 1; x++) {
      if (x % 2 == 0)
        result += "RD";
      else
        result += "RU";
    }

    if (no.first % 2 == 0)
      nR = R - (no.first + 2);
    else
      nR = R - (no.first + 1);

    for (int y = 0; y < nR; y++) {
      result += 'D';
      for (int x = 0; x < C - 1; x++) {
        if (y % 2 == 0)
          result += 'L';
        else
          result += 'R';
      }
    }
  }
  cout << result << '\n';
  return 0;
}
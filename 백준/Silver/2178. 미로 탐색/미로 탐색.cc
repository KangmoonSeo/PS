#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
#define MAX_ 12191774
using namespace std;

const int dy[4] = {1, 0, -1, 0};
const int dx[4] = {0, 1, 0, -1};

int n, m;
vector<vector<int> > visited;

bool isBoundary(int ty, int tx) {
  bool ret = ty >= 0 && ty < n && tx >= 0 && tx < m;
  return ret;
}
void print() {
  return;
  for (int j = 0; j < n; j++) {
    cout << "|";
    for (int i = 0; i < m; i++) {
      cout << setw(3) << visited[j][i];
    }
    cout << "\n";
  }
  cout << "\n";
}
void maze() {
  queue<pair<int, int> > q;
  q.push(make_pair(0, 0));
  visited[0][0] = 1;
  int cnt = 0;
  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    int tts = visited[y][x];
    q.pop();
    for (int i = 0; i < 4; i++) {
      int ty = y + dy[i];
      int tx = x + dx[i];
      if (isBoundary(ty, tx) &&
          (visited[ty][tx] == -1 || visited[ty][tx] > tts + 1)) {
        q.push(make_pair(ty, tx));
        visited[ty][tx] = tts + 1;
      }
    }
    print();
    cnt++;
  }
  cout << visited[n - 1][m - 1] <<"\n";
}

int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 실행속도 최적화 end

  cin >> n >> m;

  visited.assign(n, vector<int>(m));
  string line;
  for (int j = 0; j < n; j++) {
    cin >> line;
    for (int i = 0; i < m; i++) {
      visited[j][i] = !(bool)(line[i] - 48);
      visited[j][i] -= 1;
    }
  }
  print();
  maze();
}

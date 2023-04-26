#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int n;
bool dfs_visit[1001] = {false};
bool bfs_visit[1001] = {false};

bool adj[1001][1001] = {false};

void add(int a, int b) {
  adj[a][b] = true;
  adj[b][a] = true;
}

void dfs(int r) {
  cout << r << " ";
  dfs_visit[r] = true;
  for (int i = 1; i <= n; i++) {
    if (!dfs_visit[i] && adj[r][i]) {
      dfs(i);
    }
  }
}

void bfs(int r) {
  queue<int> q;
  bfs_visit[r] = true;
  q.push(r);
  while (!q.empty()) {
    int x = q.front();
    cout << x << " ";
    q.pop();
    for (int i = 1; i <= n; i++) {
      if (!bfs_visit[i] && adj[x][i]) {
        bfs_visit[i] = true;
        q.push(i);
      }
    }
  }
  cout << "\n";
}

int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 실행속도 최적화 end

  int m, v;  // input
  cin >> n >> m >> v;
  int i1, i2;
  for (int i = 0; i < m; i++) {
    cin >> i1 >> i2;
    add(i1, i2);
  }

  dfs(v);
  cout << "\n";
  bfs(v);
}

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

vector<int> adj[1001];

void add(int a, int b) {
  adj[a].push_back(b);
  adj[b].push_back(a);
}

void dfs(int r) {
  cout << r << " ";
  dfs_visit[r] = true;
  const int length = adj[r].size();
  for (int i = 0; i < length; i++) {  // adj list를 털어먹는 상황, 0부터 시작
    int y = adj[r][i];
    if (!dfs_visit[y]) {
      dfs(y);
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
    int length = adj[x].size();
    for (int i = 0; i < length; i++) {  // adj list를 털어먹는 상황, 0부터 시작
      int y = adj[x][i];
      if (!bfs_visit[y]) {
        bfs_visit[y] = true;
        q.push(y);
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
  for (int i = 1; i <= n; i++) {
    sort(adj[i].begin(), adj[i].end());
  }

  dfs(v);
  cout << "\n";
  bfs(v);
}

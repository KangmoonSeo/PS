#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;
int n, m;  // input

vector<vector<int> > adj;
bool isVisited[1001] = {false};

void add(int a, int b) {
  adj[a].push_back(b);
  adj[b].push_back(a);
}

int dfs(int r) {
  if (isVisited[r]) {
    return 0;
  }
  isVisited[r] = true;

  int length = adj[r].size();
  for (int i = 0; i < length; i++) {
    dfs(adj[r][i]);
  }
  return 1;
}

void func() {
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    cnt += dfs(i);
  }
  cout << cnt << "\n";
}
int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 실행속도 최적화 end

  cin >> n >> m;
  adj.assign(n + 1, vector<int>(n + 1));

  int i1, i2;
  for (int i = 0; i < m; i++) {
    cin >> i1 >> i2;
    add(i1, i2);
  }
  func();
}

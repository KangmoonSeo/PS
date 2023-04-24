#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

vector<vector<bool> > arr(101, vector<bool>(101));
vector<bool> isVisited(101);
int cnt = 0;

void add(int a, int b) {
  arr[a][b] = true;
  arr[b][a] = true;
}
void dfs(int init, int n) {
  for (int i = 1; i <= n; i++) {
    if (arr[init][i] && !isVisited[i]) {
      isVisited[i] = true;
      cnt++;
      dfs(i, n);
    }
  }
}

int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 실행속도 최적화 end

  int n, m;  // input
  cin >> n >> m;
  int p1, p2;
  for (int i = 0; i < m; i++) {
    cin >> p1 >> p2;
    add(p1, p2);
  }
  dfs(1, n);
  cout << cnt-1 << "\n";
}

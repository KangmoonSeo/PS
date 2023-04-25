#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef priority_queue<int, vector<int>, greater<int> > PQ;
bool isVisited[100001] = {false};
vector<PQ> adj(100001);
int arrCnt[100001] = {0};  // 문제 조건

void add(int a, int b) {
  adj[a].push(b);
  adj[b].push(a);
}

void bfs(int r) {
  queue<int> q;
  q.push(r);
  isVisited[r] = true;
  int cnt = 0;  // 문제 조건, BFS 실행 순서 추적

  while (!q.empty()) {
    int x = q.front();
    q.pop();
    arrCnt[x] = ++cnt;  // BFS 실행 순서 담음

    int length = adj[x].size();
    while (length--) {
      if (!isVisited[adj[x].top()]) {
        q.push(adj[x].top());
        isVisited[adj[x].top()] = true;
      }
      adj[x].pop();
    }
  }
}

int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 실행속도 최적화 end

  int n, m, r;  // input
  cin >> n >> m >> r;

  int i1, i2;
  for (int i = 0; i < m; i++) {
    cin >> i1 >> i2;
    add(i1, i2);
  }
  bfs(r);
  for (int i = 1; i <= n; i++) {
    cout << arrCnt[i] << "\n";
  }
}

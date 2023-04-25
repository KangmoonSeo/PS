#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef priority_queue<int, vector<int>, greater<int> > PQ;
bool isVisited[100001] = {false};
int arrCnt[100001] = {0};
vector<PQ> arr(100001);

void add(int a, int b) {
  arr[a].push(b);
  arr[b].push(a);
}

void bfs(int r, int n) {
  queue<int> q;
  q.push(r);
  isVisited[r] = true;
  int cnt = 0;

  while (!q.empty()) {
    int val = q.front();
    cnt++;
    arrCnt[val] = cnt;
    q.pop();
    int length = arr[val].size();
    for (int j = 0; j < length; j++) {
      if (isVisited[arr[val].top()]) {
        arr[val].pop();
        continue;
      }
      q.push(arr[val].top());
      isVisited[arr[val].top()] = true;
      arr[val].pop();
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << arrCnt[i] << "\n";
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
  bfs(r, n);
}

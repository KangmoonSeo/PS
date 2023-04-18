#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

void func(int n) {
  priority_queue<int> pq;
  int ans;
  for (int i = 0; i < n; i++) {
    cin >> ans;
    if (ans == 0) {
      if (pq.size() == 0) {
        cout << "0\n";
      } else {
        cout << pq.top() << "\n";
        pq.pop();
      }
    } else {
      pq.push(ans);
    }
  }
}

int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 실행속도 최적화 end

  int n;  // input
  cin >> n;
  func(n);
}

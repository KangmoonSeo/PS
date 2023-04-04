#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void func(int n) {
  int response;
  priority_queue<int, vector<int>, greater<int> > p_queue;

  for (int i = 0; i < n; i++) {
    cin >> response;
    if (response == 0) {
      if (p_queue.empty()) {
        cout << "0\n";
      } else {
        cout << p_queue.top() << "\n";
        p_queue.pop();
      }
    } else
      p_queue.push(response);
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

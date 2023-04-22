#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

struct compare {
  bool operator()(int a, int b) {
    if (abs(a) == abs(b)) {
      return a > b;
    }

    return abs(a) > abs(b);
  }
};
void foo(int n) {
  priority_queue<int, vector<int>, compare> pq;
  int input;
  for (int i = 0; i < n; i++) {
    cin >> input;
    if (input == 0) {
      if (pq.empty()) {
        cout << "0\n";
        continue;
      }
      cout << pq.top() << "\n";
      pq.pop();
    } else {
      pq.push(input);
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
  foo(n);
}

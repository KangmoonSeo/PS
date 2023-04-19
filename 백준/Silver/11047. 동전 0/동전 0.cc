#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

void foo(int n, int k) {
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int sum = k;
  int cnt = 0;
  
  for (int i = n - 1; sum > 0; i--) {
    if (sum >= arr[i]) {
      sum -= arr[i];
      cnt++;
      i = n;
    }
  }
  cout << cnt << "\n";
}

int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 실행속도 최적화 end

  int n, k;  // input
  cin >> n >> k;
  foo(n, k);
}

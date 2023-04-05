#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void func(vector<int>& arr) {
  sort(arr.begin(), arr.end());
  int sum = 0;
  int length = arr.size();
  for (int i = 0; i < length; i++) {
    sum += arr[i]*(length-i);
  }
  cout << sum;
}

int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 실행속도 최적화 end

  int n;  // input
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  func(arr);
}

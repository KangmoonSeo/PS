#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 실행속도 최적화 end

  int n;  // input
  cin >> n;
  vector<int> arr, res;  // 2, 4, -10, 4, -9, ...
  int tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    arr.push_back(tmp);
  }
  res.assign(arr.begin(), arr.end());
  sort(res.begin(), res.end());
  res.erase(unique(res.begin(), res.end()), res.end()); 
  // -> res는 중복 제거한 정렬 vector로 변환됨

  for (int i = 0; i < n; i++) {
    auto idx = lower_bound(res.begin(), res.end(), arr[i]);
    cout << to_string(idx - res.begin()) << " ";
  }
}

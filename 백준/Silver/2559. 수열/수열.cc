#include <algorithm>
#include <iostream>
using namespace std;
// 구간합 유형 - 기초
int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 실행속도 최적화 end

  int n, k;  // n=온도를 측정한 전체 날짜의 수, k=연속적인 날짜
  cin >> n >> k;

  int arr[100005] = {};
  int ans = -100 * k;
  for (size_t i = 1; i < n + 1; i++) {
    cin >> arr[i];
    arr[i] += arr[i - 1];
  }
  for (size_t i = k; i < n + 1; i++) {
    ans = max(ans, arr[i] - arr[i - k]);
  }
  if (n == k) ans = arr[n];
  cout << ans;
}
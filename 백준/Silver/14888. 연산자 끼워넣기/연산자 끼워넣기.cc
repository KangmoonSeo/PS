#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b

using namespace std;

int ops[4];
int arr[11];
int n;
int curMax = -1000000000;
int curMin = 1000000000;

// sol) 백트래킹을 활용한 알고리즘
void recur(int ret, int idx, int curOps[]) {
  if (idx == n) {  // 종결 조건; idx 전부 소모하면 max, min 비교
    curMax = max(curMax, ret);
    curMin = min(curMin, ret);
    return;
  }

  const int memRet = ret;
  for (int i = 0; i < 4; i++) {
    if (curOps[i] == 0) continue;  // pruning; 백트래킹 핵심 부분 !!
    ret = memRet; // 초기화
    curOps[i]--;
    if (i == 0)
      ret += arr[idx];
    else if (i == 1)
      ret -= arr[idx];
    else if (i == 2)
      ret *= arr[idx];
    else if (i == 3)
      ret /= arr[idx];
    recur(ret, idx + 1, curOps);
    curOps[i]++;
  }
}

int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 실행속도 최적화 end

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < 4; i++) {
    cin >> ops[i];
  }

  recur(arr[0], 1, ops);
  cout << curMax << "\n" << curMin << "\n";
}

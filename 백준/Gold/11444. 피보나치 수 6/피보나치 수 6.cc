#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

#define DIV 1000000007
vector<pair<long long, long long> > dp;

long long fib(long long k) {
  if (k < 2) return k;  // termination
  const int length = dp.size();
  for (int i = 0; i < length; i++) {  // dp 배열에 key가 있으면 즉시 return
    if (dp[i].first == k) return dp[i].second;
  }

  const long long val1 = fib((k + 1) / 2) % DIV;
  const long long val2 = fib((k - 1) / 2) % DIV;
  long long ret;

  if (k % 2 == 0) {  // fib(26) = fib(13)fib(13) + 2*fib(13)fib(12)
    ret = val1 * val1 + val1 * val2 * 2;
  } else {  // fib(25) = fib(13)fib(13) + fib(12)fib(12)
    ret = val1 * val1 + val2 * val2;
  }
  ret %= DIV;
  // 중복 실행 막기 위해 <key, val>를 저장
  const pair<long long, long long> save = make_pair(k, ret);
  dp.push_back(save);
  return ret;
}

int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 실행속도 최적화 end

  long long n;  // input

  cin >> n;
  cout << fib(n) << "\n";
}

#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

#define DIV 1000000007
vector<pair<long long, long long> > dp;

long long fib(long long k) {
  if (k < 2) return k;
  for (int i = 0; i < dp.size(); i++) {
    if (dp[i].first == k) {
      return dp[i].second;
    }
  }
  long long ret;
  long long val1 = fib((k + 1) / 2) % DIV;
  long long val2 = fib((k - 1) / 2) % DIV;

  if (k % 2 == 0) {  // fibo(26) -> fibo(13)fibo(13) + 2*fibo(13)*fibo(12)
    ret = val1 * val1 + 2 * val1 * val2;
  } else {  // 25-> fibo(13)fibo(13) + fibo(12)fibo(12)
    ret = val1 * val1 + val2 * val2;
  }
  pair<long long, long long> tmp = make_pair(k, ret);
  dp.push_back(tmp);
  return ret % DIV;
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

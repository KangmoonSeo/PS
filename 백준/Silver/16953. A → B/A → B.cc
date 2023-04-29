#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int result = 999999;
long b;
void recur(long r, int tts) {
  if (b < r) {
    return;
  } else if (b == r) {
    result = result > tts ? tts : result;
    return;
  }
  recur(r * 2, tts + 1);
  recur(r * 10 + 1, tts + 1);
}

int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 실행속도 최적화 end

  long a;  // input
  cin >> a >> b;
  recur(a, 1);
  if (result == 999999) result = -1;
  cout << result << "\n";
}

#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
vector<string> starBucket(3072);

void star(int n, int init) {
  if (n <= 3) {  // 종결 조건
    starBucket[init] += "  *  ";
    starBucket[init + 1] += " * * ";
    starBucket[init + 2] += "*****";
    return;
  }

  for (int i = 0; i < n / 2; i++) {  // 왼쪽 빈칸 채우기
    for (int j = 0; j < n / 2; j++) {
      starBucket[init + i] += " ";
    }
  }
  star(n / 2, init);

  star(n / 2, init + n / 2);
  for (int i = n / 2; i < n; i++) {  // 중앙 1칸 띄기
    starBucket[init + i] += " ";
  }
  star(n / 2, init + n / 2);

  for (int i = 0; i < n / 2; i++) {  // 오른쪽 빈칸 채우기
    for (int j = 0; j < n / 2; j++) {
      starBucket[init + i] += " ";
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
  star(n, 0);

  for (int i = 0; i < n; i++) {
    cout << starBucket[i] << "\n";
  }
}

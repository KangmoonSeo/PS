#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void func(int n, int m, string s) {
  string pattern = "IOI";
  for (int i = 1; i < n; i++) {
    pattern += "OI";
  }
  const int pattern_length = pattern.size();  // n*2+1

  int cnt = 0;
  int i = 0, j = 0;

  while (i < m) {
    if (s[i] == pattern[j]) {  // 1글자 match
      j++;
      if (j == pattern_length) {  // all match -> cnt++, 2칸 당김
        cnt++;
        j = j - 2;
      }
    } else if (s[i] == 'I') {
      j = 1;
    } else if (s[i] == 'O') {
      j = 0;
    }
    i++;
  }

  cout << cnt;
}

int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 실행속도 최적화 end

  int n, m;  // input
  cin >> n >> m;
  string s;
  cin >> s;
  func(n, m, s);
}

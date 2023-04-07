#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void func(int n, int m, string s) {
  string target = "IOI";
  string tmp = s;

  for (int i = 1; i < n; i++) {
    target += "OI";
  }
  int idx = -1;
  int cnt = 0;

  for (int i = 0; i < m; i++) {
    idx = tmp.find(target);
    if (idx == -1) break;

    tmp = tmp.substr(idx + 2);
    cnt++;
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

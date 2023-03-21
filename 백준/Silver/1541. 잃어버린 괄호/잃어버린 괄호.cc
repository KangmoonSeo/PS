#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void bracket(string str) {
  bool isMinus = false;
  string tmp = "";
  int sum = 0;
  for (size_t i = 0; i <= str.size(); i++) {
    if (str[i] == '+' || str[i] == '-' || i == str.size()) {
      // 연산자를 만난 경우 쌓아둔 tmp를 더해줌
      if (isMinus) {
        sum -= stoi(tmp);
      } else {
        sum += stoi(tmp);
      }
      if (str[i] == '-') isMinus = true;
      tmp = "";  // tmp 초기화
    } else {
      tmp = tmp + str[i];
    }
  }

  cout << sum;
}

int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 실행속도 최적화 end

  string str;  // input
  cin >> str;

  bracket(str);
}

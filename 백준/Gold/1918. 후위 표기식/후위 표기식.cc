#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

string solve(string const s) {
  int length = s.size();

  string memory_3 = "";  // operator +,- : 3순위
  string memory_2 = "";  // operator *,/ : 2순위
  string memory_1 = "";  // 괄호 : 1순위, 재귀꼴 불러옴

  string result;
  int braceStack = 0;
  char target;

  for (int i = 0; i < length; i++) {
    target = s[i];
    if (braceStack > 0) {
      if (target == '(') braceStack++;
      if (target == ')') braceStack--;
      if (braceStack == 0) {        // brace memory end
        result += solve(memory_1);  // 괄호 벗겨서 재귀
        memory_1 = "";
      } else {
        memory_1 += target;
      }
    } else if (target == '(') {  // brace memory start
      braceStack++;
    } else if (target == '+' || target == '-') {
      result += memory_2 + memory_3;
      memory_2 = "";
      memory_3 = target;
    } else if (target == '*' || target == '/') {
      result += memory_2;
      memory_2 = target;
    } else {  // 피연산자
      result.push_back(target);
    }
  }
  result += memory_2 + memory_3;

  return result;
}

int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 실행속도 최적화 end

  string s;  // input
  cin >> s;

  cout << solve(s) << "\n";
}

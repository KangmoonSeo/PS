#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

/*
 * add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을
 * 무시한다.
 * remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을
 * 무시한다.
 * check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
 * toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
 * all: S를 {1, 2, ..., 20} 으로 바꾼다.
 * empty: S를 공집합으로 바꾼다.
 */
void func(int n) {
  vector<int> arr(21);
  vector<int> _all(21);
  vector<int> _empty(21);
  for (int i = 0; i < 21; i++) _all[i] = i;

  string command;
  int input;

  for (int i = 0; i < n; i++) {
    cin >> command;
    if (command == "all") {
      arr.assign(_all.begin(), _all.end());

    } else if (command == "empty") {
      arr.assign(_empty.begin(), _empty.end());

    } else if (command == "add") {
      cin >> input;
      arr[input] = input;
    } else if (command == "remove") {
      cin >> input;
      arr[input] = 0;
    } else if (command == "check") {
      cin >> input;
      cout << ((arr[input] == input) ? 1 : 0) << "\n";

    } else if (command == "toggle") {
      cin >> input;
      arr[input] = arr[input] == 0 ? input : 0;
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
  func(n);
}

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void set(int n) {
  vector<int> _all(21);
  for (int i = 0; i < 21; i++) _all[i] = i;
  vector<int> _empty(21);

  vector<int> arr(21);

  string command;
  int input;

  for (int i = 0; i < n; i++) {
    cin >> command;

    if (command == "all") {
      arr.assign(_all.begin(), _all.end());
      continue;
    }
    if (command == "empty") {
      arr.assign(_empty.begin(), _empty.end());
      continue;
    }
    if (command == "add") {
      cin >> input;
      arr[input] = input;
      continue;
    }
    if (command == "remove") {
      cin >> input;
      arr[input] = 0;
      continue;
    }
    if (command == "check") {
      cin >> input;
      cout << ((arr[input] == input) ? 1 : 0) << "\n";
      continue;
    }
    if (command == "toggle") {
      cin >> input;
      arr[input] = ((arr[input] == 0) ? input : 0);
      continue;
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
  set(n);
}

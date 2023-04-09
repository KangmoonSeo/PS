#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void set(int n) {
  int BIT = 0;
  string command;
  int input;

  for (int i = 0; i < n; i++) {
    cin >> command;

    if (command == "all") {
      BIT = (1 << 21) - 1;
      continue;
    }
    if (command == "empty") {
      BIT = 0;
      continue;
    }
    if (command == "add") {
      cin >> input;
      BIT = BIT | (1 << input);
      continue;
    }
    if (command == "remove") {
      cin >> input;
      BIT = BIT & ~(1 << input);
      continue;
    }
    if (command == "check") {
      cin >> input;
      cout << ((BIT & (1 << input)) ? 1 : 0) << "\n";
      continue;
    }
    if (command == "toggle") {
      cin >> input;
      BIT = BIT ^ (1 << input);
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

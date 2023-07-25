#include <bits/stdc++.h>
using namespace std;

int n;
string str = "";

void check() {
  int sum = 0;
  string mem = "";
  mem += str[0];
  bool isPlus = true;

  for (int i = 2; i < str.size(); i += 2) {
    if (str[i - 1] == '+') {
      sum += isPlus ? stoi(mem) : stoi(mem) * -1;
      isPlus = true;
      mem = "";
    } else if (str[i - 1] == '-') {
      sum += isPlus ? stoi(mem) : stoi(mem) * -1;
      isPlus = false;
      mem = "";
    }
    mem += str[i];
  }
  sum += isPlus ? stoi(mem) : stoi(mem) * -1;
  if (sum == 0) cout << str << "\n";
}

void BT(int i = 1) {
  str += (i + '0');
  if (i < n) {
    str += ' ';
    BT(i + 1);
    str.pop_back();

    str += '+';
    BT(i + 1);
    str.pop_back();

    str += '-';
    BT(i + 1);
    str.pop_back();
  }
  if (i == n) check();
  str.pop_back();
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    BT();
    cout << "\n";
  }
}

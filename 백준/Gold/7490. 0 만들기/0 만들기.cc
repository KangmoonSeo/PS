#include <bits/stdc++.h>
using namespace std;

const char ops[3] = {' ', '+', '-'};
int n;
string str = "";

void check() {
  int sum = 0;
  string mem = "";
  mem += str[0];
  bool isPlus = true;

  for (int i = 2; i < str.size(); i += 2) {
    char op = str[i - 1];
    if (op != ' ') {
      sum += isPlus ? stoi(mem) : -stoi(mem);
      mem = "";
      isPlus = op == '+';
    }
    mem += str[i];
  }
  sum += isPlus ? stoi(mem) : -stoi(mem);
  if (sum == 0) cout << str << "\n";
}

void BT(int i = 1) {
  str += (i + '0');
  if (i == n) check();
  if (i < n) {
    for (char op : ops) {
      str += op;
      BT(i + 1);
      str.pop_back();
    }
  }
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

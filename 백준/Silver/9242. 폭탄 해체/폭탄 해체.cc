#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> vec;
map<string, int> gtoi;
vector<string> numbers;

bool init() {
  // set gtoi
  gtoi["***\n* *\n* *\n* *\n***\n"] = 0;
  gtoi["  *\n  *\n  *\n  *\n  *\n"] = 1;
  gtoi["***\n  *\n***\n*  \n***\n"] = 2;
  gtoi["***\n  *\n***\n  *\n***\n"] = 3;
  gtoi["* *\n* *\n***\n  *\n  *\n"] = 4;
  gtoi["***\n*  \n***\n  *\n***\n"] = 5;
  gtoi["***\n*  \n***\n* *\n***\n"] = 6;
  gtoi["***\n  *\n  *\n  *\n  *\n"] = 7;
  gtoi["***\n* *\n***\n* *\n***\n"] = 8;
  gtoi["***\n* *\n***\n  *\n***\n"] = 9;

  // parse vec -> graphic
  for (int j = 0; j < 5; j++) {
    if ((vec[j].size() + 1) % 4 > 0) return false;
  }

  for (int i = 0; i < vec[0].size(); i += 4) {
    string number;
    for (int j = 0; j < 5; j++) {
      number += vec[j].substr(i, 3);
      number += "\n";
    }
    numbers.push_back(number);
  }

  return true;
}

bool solve() {
  if (!init()) return false;

  int ans = 0;
  for (string num : numbers) {
    if (gtoi.find(num) == gtoi.end()) return false;
    ans *= 10;
    ans += gtoi[num];
  }
  return (ans % 6 == 0);
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  for (int i = 0; i < 5; i++) {
    string input;
    getline(cin, input);
    vec.push_back(input);
  }

  string ans = solve() ? "BEER!!" : "BOOM!!";
  cout << ans;
}

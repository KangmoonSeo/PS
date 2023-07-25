#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<string> > vec(10, vector<string>(0));
vector<vector<string> > ans(10, vector<string>(0));
string tmp = "";

void makeSet(int i = 1) {
  tmp += (i + '0');
  vec[i].push_back(tmp);
  if (i < 9) {
    tmp += ' ';
    makeSet(i + 1);
    tmp.pop_back();

    tmp += '+';
    makeSet(i + 1);
    tmp.pop_back();

    tmp += '-';
    makeSet(i + 1);
    tmp.pop_back();
  }
  tmp.pop_back();
}

void calc() {
  for (string s : vec[n]) {
    int sum = 0;
    string mem = "";
    bool isPlus = true;
    mem += s[0];

    for (int i = 2; i < s.size(); i += 2) {
      if (s[i - 1] == '+') {
        sum += isPlus ? stoi(mem) : stoi(mem) * -1;
        isPlus = true;
        mem = "";
      } else if (s[i - 1] == '-') {
        sum += isPlus ? stoi(mem) : stoi(mem) * -1;
        isPlus = false;
        mem = "";
      }
      mem += s[i];
    }
    sum += isPlus ? stoi(mem) : stoi(mem) * -1;
    if (sum == 0) ans[n].push_back(s);
  }
}
void solve() {
  cin >> n;
  if (ans[n].empty()) calc();
  for (string str : ans[n]) {
    cout << str << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  int T;
  cin >> T;
  makeSet();
  while (T--) {
    solve();
    cout << "\n";
  }
}

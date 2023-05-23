#include <bits/stdc++.h>
using namespace std;
int n, m;
bool isError[10] = {};
vector<char> buttons;
string bt;
int length;
int mem = 500000;
vector<int> results;

bool makeSet(int TTL = 0) {
  if (TTL == length) {
    int res = stoi(bt);
    if (res > n) {
      results.push_back(res);
      return false;
    } else {
      mem = res;
      return true;
    }
  }
  for (int i = 0; i < buttons.size(); i++) {
    bt.push_back(buttons[i]);
    if (makeSet(TTL + 1) == false) return false;
    bt.pop_back();
  }
  return true;
}

void solve() {
  length = to_string(n).size();
  for (int i = 0; i <= 9; i++) {
    if (!isError[i]) buttons.push_back(i + '0');
  }

  // easyAns start
  int easyAns = abs(n - 100);
  if (m == 10) {
    cout << easyAns << "\n";
    return;
  } else if (m == 0) {
    cout << min(easyAns, length) << "\n";
    return;
  } else if (m == 9 && !isError[0]) {
    cout << min(easyAns, n + 1) << "\n";
    return;
  }
  // easyAns end

  // hardAns start
  makeSet();
  if (mem < 500000) results.push_back(mem);

  if (length > 1) {
    string str;
    for (int i = 0; i < length - 1; i++) {
      str += buttons.back();
    }
    results.push_back(stoi(str));
  }
  if (length < 6) {
    string str;
    for (int i = 0; i < length + 1; i++) {
      if (i == 0 && buttons[0] == '0')
        str += buttons[1];
      else
        str += buttons[0];
    }
    results.push_back(stoi(str));
  }
  int hardAns = 1e9;
  for (int i = 0; i < results.size(); i++) {
    if (hardAns > abs(results[i] - n) + to_string(results[i]).size()) {
      hardAns = abs(results[i] - n) + to_string(results[i]).size();
    }
  }
  // hardAns end
  cout << min(easyAns, hardAns) << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n >> m;
  int input;
  for (int i = 0; i < m; i++) {
    cin >> input;
    isError[input] = true;
  }
  solve();
}

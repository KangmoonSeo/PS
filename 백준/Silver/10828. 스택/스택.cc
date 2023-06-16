#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> vec;

void solve() {
  string str;
  cin >> str;
  // push X
  if (str == "push") {
    int x;
    cin >> x;
    vec.push_back(x);
  }
  // pop
  if (str == "pop") {
    if (vec.empty()) {
      cout << "-1\n";
      return;
    }
    cout << vec.back() << "\n";
    vec.pop_back();
  }
  // size
  if (str == "size") {
    cout << vec.size() << "\n";
  }

  // empty
  if (str == "empty") {
    if (vec.empty()) {
      cout << "1\n";
    } else {
      cout << "0\n";
    }
  }
  // top
  if (str == "top") {
    if (vec.empty()) {
      cout << "-1\n";
      return;
    }
    cout << vec.back() << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n;
  while (n--) {
    solve();
  }
}

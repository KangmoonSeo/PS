#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
  deque<int> deq;
  string s1;
  int i2;
  while (n--) {
    cin >> s1;
    if (s1 == "push_front") {
      cin >> i2;
      deq.push_front(i2);
    } else if (s1 == "push_back") {
      cin >> i2;
      deq.push_back(i2);
    } else if (s1 == "pop_front") {
      if (deq.empty())
        cout << "-1\n";
      else {
        cout << deq.front() << "\n";
        deq.pop_front();
      }

    } else if (s1 == "pop_back") {
      if (deq.empty())
        cout << "-1\n";
      else {
        cout << deq.back() << "\n";
        deq.pop_back();
      }
    } else if (s1 == "size") {
      cout << deq.size() << "\n";
    } else if (s1 == "empty") {
      cout << deq.empty() << "\n";
    } else if (s1 == "front") {
      if (deq.empty())
        cout << "-1\n";
      else {
        cout << deq.front() << "\n";
      }
    } else if (s1 == "back") {
      if (deq.empty())
        cout << "-1\n";
      else {
        cout << deq.back() << "\n";
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n;
  solve();
}

#include <bits/stdc++.h>
using namespace std;

int n, s;
queue<int> q;
void solve() {
  int sum = 0;
  int input;
  bool fl = false;
  for (int i = 0; i < n; i++) {
    cin >> input;
    sum += input;
    q.push(input);
    if (fl) {
      sum -= q.front();
      q.pop();
    }
    while (sum >= s) {
      fl = true;
      if (sum - q.front() < s) break;
      sum -= q.front();
      q.pop();
    }
  }
  if (!fl)
    cout << "0\n";
  else
    cout << q.size() << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n >> s;
  solve();
}

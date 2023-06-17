#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
  // function acts here
  int sum = 1;
  int head = 0;

  for (int i = 0; i < n; i++) {
    head++;
    if (head >= sum) {
      sum++;
      head = 1;
    }
  }
  if (sum % 2 == 0)
    cout << sum - head << "/" << head << "\n";
  else
    cout << head << "/" << sum - head << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n;
  solve();
}

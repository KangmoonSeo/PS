#include <bits/stdc++.h>
using namespace std;

void solve(int t) {
  int r = 64;
  int mini = 64;
  int cnt = 1;
  while (r != t) {
    mini /= 2;
    cnt++;
    if (r - mini >= t) {
      r -= mini;
      cnt--;
    }
  } 
  cout << cnt << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  int t;  // input
  cin >> t;
  solve(t);
}

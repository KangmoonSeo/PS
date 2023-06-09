#include <bits/stdc++.h>
using namespace std;

int n;
bool isSelf[10001] = {};
int checkNum(int v) {
  int sum = v;
  while (v > 0) {
    sum += v % 10;
    v /= 10;
  }
  return sum;
}
void solve() {
  for (int i = 1; i <= 10000; i++) {
    int nxt = checkNum(i);
    if (!isSelf[i]) {
      cout << i << "\n";
    }
    if (nxt <= 10000) isSelf[nxt] = true;
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  solve();
}

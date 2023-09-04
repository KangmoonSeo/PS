#include <bits/stdc++.h>
using namespace std;

string str;
int quack[5] = {};

int check(int v) {
  quack[v]++;
  int mem = 1e9;
  for (int i = 0; i < 5; i++) {
    if (quack[i] > mem) return -1;
    mem = quack[i];
  }
  return quack[0] - quack[4];
}
void solve() {
  int n = str.size();
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int v;
    if (str[i] == 'q') {
      v = 0;
    } else if (str[i] == 'u') {
      v = 1;
    } else if (str[i] == 'a') {
      v = 2;
    } else if (str[i] == 'c') {
      v = 3;
    } else {
      v = 4;
    }
    int result = check(v);
    if (result == -1) {
      ans = -1;
      break;
    } else {
      ans = max(result, ans);
    }
  }
  int mem = quack[0];
  for (int i = 1; i < 5; i++) {
    if (quack[i] != mem) {
      ans = -1;
      break;
    }
    mem = quack[i];
  }

  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> str;
  solve();
}

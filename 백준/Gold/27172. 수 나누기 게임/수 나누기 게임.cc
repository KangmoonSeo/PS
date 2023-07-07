#include <bits/stdc++.h>
using namespace std;

int n, MAX_X = 0;
int user[1000001] = {};  // user number of x
int score[100001] = {};  // score of user

void solve() {
  int x;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    user[x] = i;
    MAX_X = max(x, MAX_X);
  }
  for (int x_i = 1; x_i <= MAX_X; x_i++) {
    if (user[x_i] <= 0) continue;
    for (int x_j = x_i * 2; x_j <= MAX_X; x_j += x_i) {
      if (user[x_j] > 0) {
        score[user[x_i]]++;
        score[user[x_j]]--;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << score[i] << " ";
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n;
  solve();
}

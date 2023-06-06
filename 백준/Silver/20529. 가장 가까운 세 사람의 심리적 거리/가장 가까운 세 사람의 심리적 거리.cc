#include <bits/stdc++.h>
using namespace std;

const char mbti[4] = {'I', 'S', 'T', 'J'};
int n, b[32];

int dist(int a, int b) {
  int BIT = a ^ b;
  int ret = 0;
  while (BIT > 0) {
    ret += BIT % 2;
    BIT /= 2;
  }
  return ret;
}

void solve() {
  cin >> n;
  string input;
  if (n > 32) {  // n > 2 * 16
    while (n--) {
      cin >> input;
    }
    cout << "0\n";
    return;
  }

  // n < 33 => brute force
  fill_n(b, 32, 0);
  for (int i = 0; i < n; i++) {
    cin >> input;
    for (int j = 0; j < 4; j++) {
      b[i] += (input[j] == mbti[j]) << j;  // convert mbti to bit
    }
  }
  int t1, t2, t3, sum;
  int ans = 12;
  for (int i = 0; i < n; i++) {  // nC3
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        sum = dist(b[i], b[j]) + dist(b[j], b[k]) + dist(b[k], b[i]);
        ans = min(ans, sum);
        if (ans == 0) i = n, j = n, k = n;  // break all loop
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}

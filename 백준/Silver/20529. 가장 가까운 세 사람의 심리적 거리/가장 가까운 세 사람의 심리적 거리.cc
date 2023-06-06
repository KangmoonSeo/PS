#include <bits/stdc++.h>
using namespace std;

int n;
int arr[32] = {};
const char mbti[4] = {'I', 'S', 'T', 'J'};

int getLength(int a, int b) {
  int BIT = a ^ b;
  int ret = 0;
  while (BIT > 0) {
    ret += BIT % 2;
    BIT /= 2;
  }
  return ret;
}
void solve() {
  fill_n(arr, 32, 0);
  cin >> n;
  string input;
  if (n > 32) {  // 2 * 16 + 1
    while (n--) {
      cin >> input;
    }
    cout << "0\n";
    return;
  }

  for (int i = 0; i < n; i++) {  // max n = 32 -> brute force
    cin >> input;
    for (int j = 0; j < 4; j++) {
      arr[i] += (input[j] == mbti[j]) << j;  // convert mbti to bit
    }
  }
  int t1, t2, t3, sum, ans = 12;
  for (int i = 0; i < n; i++) {
    t1 = arr[i];
    for (int j = i + 1; j < n; j++) {
      t2 = arr[j];
      for (int k = j + 1; k < n; k++) {
        t3 = arr[k];
        sum = getLength(t1, t2) + getLength(t2, t3) + getLength(t3, t1);
        ans = min(ans, sum);
        if (ans == 0) i = n, j = n, k = n;  // break;
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

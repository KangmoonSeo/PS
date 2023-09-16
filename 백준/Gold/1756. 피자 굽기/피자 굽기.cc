#include <bits/stdc++.h>
using namespace std;

int d, n, input;
vector<int> vec;

void solve() {
  int start = 0;
  int pos = 0;
  int end = vec.size() - 1;

  for (int i = 0; i < n; i++) {
    cin >> input;
    if (end < 0 || input > vec[0]) {
      cout << 0;
      return;
    }
    start = 0;
    while (true) {
      if (start > end) {
        end = pos - 1;
        break;
      }
      int mid = (start + end) / 2;
      if (input > vec[mid])
        end = mid - 1;
      else {
        pos = mid;
        start = mid + 1;
      }
    }
  }
  cout << pos + 1 << "\n";
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> d >> n;
  for (int i = 0; i < d; i++) {
    cin >> input;
    if (!vec.empty()) input = min(input, vec.back());
    vec.push_back(input);
  }
  solve();
}

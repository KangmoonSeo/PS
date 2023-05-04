#include <bits/stdc++.h>
using namespace std;

int bound(vector<int> arr, int left, int right, int input) {
  while (left < right) {
    int mid = (left + right) / 2;
    if (arr[mid] > input) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  return right;
}

void solve(int n = 0) {
  vector<int> ans;
  int input;
  while (n--) {
    cin >> input;

    if (ans.empty() || ans.back() > input) {
      ans.push_back(input);
    } else {
      int j = bound(ans, 0, ans.size(), input);
      ans[j] = input;
    }
  }
  cout << ans.size() << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  int n;  // input
  cin >> n;
  solve(n);
}

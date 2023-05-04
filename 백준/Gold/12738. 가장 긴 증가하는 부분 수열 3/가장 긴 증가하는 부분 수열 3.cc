#include <bits/stdc++.h>
using namespace std;

void solve(int n = 0) {
  vector<int> arr;
  int input;
  while (n--) {
    cin >> input;

    if (arr.empty() || arr.back() < input) {
      arr.push_back(input);
    } else {
      int j = lower_bound(arr.begin(), arr.end(), input) - arr.begin();
      arr[j] = input;
    }
  }
  cout << arr.size() << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  int n;  // input
  cin >> n;
  solve(n);
}

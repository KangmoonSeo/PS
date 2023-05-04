#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  int n;  // input
  cin >> n;
  vector<int> ans;

  int input;
  while (n--) {
    cin >> input;

    if (ans.empty() || ans.back() < input) {
      ans.push_back(input);
    } else {
      int j = lower_bound(ans.begin(), ans.end(), input) - ans.begin();
      ans[j] = input;
    }
  }
  cout << ans.size() << "\n";
}

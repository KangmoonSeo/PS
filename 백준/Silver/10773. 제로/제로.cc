#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> vec;

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n;

  int input;
  for (int i = 0; i < n; i++) {
    cin >> input;
    if (input == 0)
      vec.pop_back();
    else
      vec.push_back(input);
  }
  int ans = 0;
  int length = vec.size();
  for (int i = 0; i < length; i++) {
    ans += vec[i];
  }
  cout << ans << "\n";
}

#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1000001];
int ans[1000001];
vector<int> vec;
void solve() {
  for (int i = n; i >= 1; i--) {
    while (!vec.empty() && arr[i] >= vec.back()) {
      vec.pop_back();
    }
    ans[i] = vec.empty() ? -1 : vec.back();
    vec.push_back(arr[i]);
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  solve();
}

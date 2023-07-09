#include <bits/stdc++.h>
using namespace std;

int n;
int arr[500001];
int cnt[8001] = {};
int cnt_i = 0;
vector<int> cnt_max;
int cnt_val = 0;
int min_val = 1e9;
int max_val = -1e9;
int sum = 0;

void solve() {
  // a 산술평균
  int ans = round((double)(sum) / n);
  cout << ans << "\n";
  // b 중앙값
  sort(arr, arr + n);
  cout << arr[n / 2] << "\n";

  // c 최빈값
  for (int i = 0; i < 8001; i++) {
    if (cnt_val < cnt[i]) {
      cnt_val = cnt[i];
      cnt_i = i;
    }
  }
  for (int i = 0; i < 8001; i++) {
    if (cnt_val == cnt[i]) cnt_max.push_back(i - 4000);
  }
  ans = cnt_max.size() > 1 ? cnt_max[1] : cnt_max[0];
  cout << ans << "\n";
  // d 범위
  cout << max_val - min_val << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    // a
    sum += arr[i];
    // b

    // c
    cnt[4000 + arr[i]]++;

    // d
    max_val = max(max_val, arr[i]);
    min_val = min(min_val, arr[i]);
  }

  solve();
}

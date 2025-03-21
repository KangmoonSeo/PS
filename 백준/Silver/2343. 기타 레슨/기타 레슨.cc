#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[100001];
/**
 * 블루레이에는 총 n개의 강의가 들어감,
 * n: 강의의 수
 * m: M개의 블루레이
 *
 * 각 강의의 길이는 10,000분을 넘지 않음
 */

bool condition(int len) {
  // 매개변수 len으로 커버가 되는 경우; 복잡도: O(n)
  int cnt = 1;
  int u = 0;

  for (int v = 1; v <= n; v++) {
    int buf = arr[v] - arr[u];
    if (arr[v] - arr[v - 1] > len) return false;
    if (buf > len) {
      cnt += 1;  // 새 테이프 장전
      u = v - 1;
    }
  }
  return (cnt <= m);  // 지금 len으로 내용물을 전부 담을 수 있는가?
}

int bsearch(int l, int r) {
  if (l == r) return r;
  //
  int mid = (l + r) / 2;
  if (condition(mid)) {
    return bsearch(l, mid);
  } else {
    return bsearch(mid + 1, r);
  }
}

int solve() {
  arr[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    arr[i] += arr[i - 1];
  }
  int min_len = 0;
  int max_len = arr[n];
  int ans = bsearch(min_len, max_len);

  return ans;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n >> m;
  int ans = solve();
  cout << ans << "\n";
}

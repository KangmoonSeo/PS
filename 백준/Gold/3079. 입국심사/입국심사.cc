#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m;
ll arr[100001];
/**
 * m: 상근이와 친구들 인원수
 * n: 입국심사대의 개수
 * T_k: k번 심사대에 앉아있는 심사관이 한 명을 심사하는 데에 드는 시간
 */

bool condition(ll len) {
  //
  ll cnt = 0;  // len 시간을 꽉차게 돌리면 처리할 수 있는 용량
  for (int i = 0; i < n; i++) {
    ll capacity = (len / arr[i]);  // len에 확실히 처리할 수 있는 인원
    cnt += capacity;

    if (cnt > m) break;
  }
  return (cnt >= m);  // len 시간 안에 m명 이상 커버 가능한가?
}

ll bsearch(ll l, ll r) {
  ll mid = (l + r) / 2;

  if (l == r) return l;

  if (condition(mid)) {
    return bsearch(l, mid);
  } else {
    return bsearch(mid + 1, r);
  }
}

ll solve() {
  // function works here

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);

  ll min_len = 0;
  ll max_len = arr[n - 1] * m;
  ll ans = bsearch(min_len, max_len);

  return ans;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n >> m;
  ll ans = solve();
  cout << ans << "\n";
}

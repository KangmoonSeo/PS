#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;

bool validate(ll k) { return (n == k * (k + 1) / 2); }
ll solve() {
  cin >> n;

  long double validator = n * 2 + 0.25;
  ll k_1 = floor(sqrt(validator));
  ll k = ceil(sqrt(validator));

  if (validate(k_1)) return k_1;
  if (validate(k)) return k;

  return -1;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  int T;
  cin >> T;
  for (int test_case = 1; test_case <= T; test_case++) {
    auto ret = solve();
    cout << "#" << test_case << " " << ret << "\n";
  }
}

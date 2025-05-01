#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a1, b1, a2, b2;
/**
 * A/B 2개 합의 기약분수
 *
 *
 *
 *
 */
ll gcd(ll a, ll b) {
  //
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}
void solve() {
  // function works here

  ll a_out = 0;
  ll b_out = 0;

  b_out = b1 * b2;
  a_out = a1 * b2 + a2 * b1;

  ll gcd_out = gcd(a_out, b_out);
  a_out /= gcd_out;
  b_out /= gcd_out;

  cout << a_out << " " << b_out << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> a1 >> b1 >> a2 >> b2;
  solve();
}

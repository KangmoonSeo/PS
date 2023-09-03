#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef long long ll;
typedef pair<ll, ll> pii;

pii A, B, C, D;

int CCW(pii a, pii b, pii c) {
  ll ret = a.x * b.y + b.x * c.y + c.x * a.y;
  ret -= a.y * b.x + b.y * c.x + c.y * a.x;

  if (ret > 0)
    return 1;
  else if (ret == 0)
    return 0;
  else
    return -1;
}

void solve() {
  if (A > B) swap(A, B);
  if (C > D) swap(C, D);

  int abc = CCW(A, B, C);
  int abd = CCW(A, B, D);
  int cda = CCW(C, D, A);
  int cdb = CCW(C, D, B);

  bool ans = 0;
  if (abc * abd == 0 && cda * cdb == 0) {
    ans = (A <= D && C <= B);
  } else {
    ans = (abc * abd <= 0 && cda * cdb <= 0);
  }
  cout << (ans ? "1\n" : "0\n");
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> A.x >> A.y >> B.x >> B.y;
  cin >> C.x >> C.y >> D.x >> D.y;

  solve();
}

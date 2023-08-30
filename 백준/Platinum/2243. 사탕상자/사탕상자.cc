#include <bits/stdc++.h>
using namespace std;

int n, B, arr[1000001], seg[4000001];

int search(int v) {
  int p = 1;
  while (p < B) {
    p *= 2;
    if (seg[p] < v) {
      v -= seg[p];
      p += 1;
    }
  }
  return p - (B - 1);
}
void update(int v, int cnt) {
  v += (B - 1);
  seg[v] += cnt;
  while (v /= 2) {
    seg[v] = seg[v * 2] + seg[v * 2 + 1];
  }
}

void solve() {
  int a, b, c;
  for (B = 1; B < 1000001; B <<= 1)
    ;  // set B
  while (n--) {
    cin >> a;
    if (a == 1) {
      cin >> b;
      int x = search(b);
      cout << x << "\n";
      update(x, -1);
    } else {
      cin >> b >> c;
      update(b, c);
    }
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n;
  solve();
}

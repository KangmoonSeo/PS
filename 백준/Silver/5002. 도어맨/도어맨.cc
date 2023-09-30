#include <bits/stdc++.h>
using namespace std;

int x, cnt[2] = {};  // W: 0, M: 1

string str;

int getb(int i) {
  if (str[i] == 'W') {
    return 0;
  } else {
    return 1;
  }
}
int diff() {
  int n1 = cnt[0], n2 = cnt[1];
  if (n1 < n2) swap(n1, n2);
  return n1 - n2;
}
void solve() {
  int ans = 0;
  int len = str.size();

  for (int i = 0; i < len; i++) {
    int u = getb(i);
    cnt[u]++;
    if (diff() <= x) continue;
    // 입뺀
    cnt[u]--;
    if (i == len - 1) continue;
    int v = getb(i + 1);

    if (u == v) break;

    cnt[u]++;
    cnt[v]++;
    i++;
  }
  cout << cnt[0] + cnt[1] << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> x;
  cin >> str;
  solve();
}

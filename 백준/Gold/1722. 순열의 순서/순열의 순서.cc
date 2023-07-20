#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int n, sel;

ll C[22];
void setC() {
  C[0] = 1;
  for (int i = 1; i <= n; i++) {
    C[i] = i * C[i - 1];
  }
  C[0] = 0;
}

void sol1() {
  ll m;
  cin >> m;
  m--;
  int ans[21] = {};
  bool visited[21] = {};
  for (int i = 1; i <= n; i++) {
    ll tmp = m;
    if (i < n) tmp = m / C[n - i];

    int nxt = 0;
    for (int j = 1; j <= n; j++) {
      if (visited[j]) continue;
      if (nxt == tmp) {
        visited[j] = true;
        ans[i] = j;
      }
      nxt++;
    }
    if (i < n) m %= C[n - i];
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}

void sol2() {
  int arr[21];
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    arr[i]--;
  }
  ll ans = 1L;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      if (arr[i] < arr[j]) arr[j]--;
    }
    ans += arr[i] * C[n - i];
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n >> sel;
  setC();
  if (sel == 1) {
    sol1();
  } else {
    sol2();
  }
}

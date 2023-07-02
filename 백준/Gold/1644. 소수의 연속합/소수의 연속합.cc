#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
  if (n == 1) {
    cout << "0\n";
    return;
  }
  vector<int> seq;
  vector<bool> isPrime(n + 1, true);
  seq.push_back(2);
  for (int i = 3; i <= n; i += 2) {
    if (!isPrime[i]) continue;
    seq.push_back(i);
    if (i > 2001) continue;  // i > sqrt(n)
    for (int j = i * i; j <= n; j += i) isPrime[j] = false;
  }

  int len = seq.size();
  int l = 0, r = 1;
  int sum = seq[l];  // [l, r)
  int cnt = 0;
  while (r <= len) {
    if (n >= sum) {
      if (n == sum) cnt++;
      sum += seq[r++];
    } else {
      sum -= seq[l++];
    }
  }
  cout << cnt << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n;
  solve();
}

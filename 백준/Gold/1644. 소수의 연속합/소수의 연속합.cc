#include <bits/stdc++.h>
using namespace std;

int n;

vector<int> getPrime() {
  vector<int> set;
  bool isNotPrime[4000001] = {};
  for (int i = 2; i <= n; i++) {
    if (isNotPrime[i]) continue;
    set.push_back(i);
    for (int j = i; j <= n; j += i) isNotPrime[j] = true;
  }
  return set;
}

void solve() {
  if (n == 1) {
    cout << "0\n";
    return;
  }
  vector<int> seq = getPrime();

  int len = seq.size();
  int l = 0, r = 1;
  int sum = seq[l];  // [l, r)
  int cnt = 0;
  while (l < r && r <= len) {
    if (n == sum) {
      cnt++;
      sum += seq[r];
      r++;
    } else if (n > sum) {
      sum += seq[r];
      r++;
    } else {
      sum -= seq[l];
      l++;
    }
  }
  cout << cnt << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n;
  solve();
}

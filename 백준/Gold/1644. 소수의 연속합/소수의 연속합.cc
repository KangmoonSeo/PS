#include <bits/stdc++.h>
using namespace std;

int n;

vector<int> getSeq() {
  // 에라토스테네스의 체
  vector<int> tmp;
  vector<int> ret;
  for (int i = 0; i <= n; i++) {
    tmp.push_back(i);
  }
  for (int i = 2; i <= n; i++) {
    if (tmp[i] == 0) continue;
    ret.push_back(i);
    for (int j = 1; i * j <= n; j++) {
      tmp[i * j] = 0;
    }
  }
  return ret;
}

void solve() {
  if (n == 1) {
    cout << "0\n";
    return;
  }
  vector<int> seq = getSeq();
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

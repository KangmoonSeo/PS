#include <bits/stdc++.h>
using namespace std;
typedef pair<unsigned long long, unsigned long long> pii;
struct cmp {
  bool operator()(pii a, pii b) {
    bool ret;
    if (a.second == b.second)
      ret = a.first > b.first;
    else
      ret = a.second > b.second;
    return ret;
  }
};
priority_queue<pii, vector<pii>, cmp> pq;

void solve() {
  int length = pq.size();
  int cnt = 0;
  unsigned long long rest = 0;
  for (int i = 0; i < length; i++) {
    pii p = pq.top();
    if (p.first >= rest) {
      cnt++;
      rest = p.second;
    }
    pq.pop();
  }
  cout << cnt << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  int n;  // input
  cin >> n;
  unsigned long long i1, i2;
  while (n--) {
    cin >> i1 >> i2;
    pq.push(make_pair(i1, i2));
  }
  solve();
}

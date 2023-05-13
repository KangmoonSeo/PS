#include <bits/stdc++.h>
typedef unsigned long long ull;
using namespace std;

void combine() {
  priority_queue<ull, vector<ull>, greater<ull> > pq;
  int n, input;
  cin >> n;
  while (n--) {
    cin >> input;
    pq.push(input);
  }
  ull ans = 0;
  while (pq.size() > 1) {
    ull i1 = pq.top();
    pq.pop();
    ull i2 = pq.top();
    pq.pop();
    ans += i1 + i2;
    pq.push(i1 + i2);
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  int T;  // input
  cin >> T;
  while (T--) {
    combine();
  }
}

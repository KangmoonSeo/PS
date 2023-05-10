#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;
void solve() {
  int ans = 0;
  while (pq.size() > 1) {
    int a = pq.top();
    pq.pop();
    int b = pq.top();
    pq.pop();
    ans += a + b;
    pq.push(a + b);
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  int n, input;  // input
  cin >> n;
  while (n--) {
    cin >> input;
    pq.push(input);
  }
  solve();
}

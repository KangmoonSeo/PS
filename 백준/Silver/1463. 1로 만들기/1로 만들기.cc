#include <bits/stdc++.h>
#define max(a, b) a > b ? a : b
#define min(a, b) a > b ? b : a
using namespace std;
int n;
bool visited[1000001] = {};
void solve() {
  queue<pair<int, int> > q;
  q.push(make_pair(n, 0));
  visited[n] = true;
  while (!q.empty()) {
        int val = q.front().first;
    int cnt = q.front().second;
    visited[val] = true;
    q.pop();
    if (val == 1) {
      cout << cnt << "\n";
      return;
    }
    if (val % 3 == 0 && !visited[val / 3]) q.push(make_pair(val / 3, cnt + 1));
    if (val % 2 == 0 && !visited[val / 2]) q.push(make_pair(val / 2, cnt + 1));
    if (!visited[val - 1]) q.push(make_pair(val - 1, cnt + 1));
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n;
  solve();
}

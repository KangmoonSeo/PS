#include <bits/stdc++.h>
using namespace std;

int n, k;

void solve() {
  map<int, bool> visited;
  queue<pair<int, int> > q;
  int ans = 0;
  q.push(make_pair(n, 0));
  visited[n] = true;
  int endTime = 100001;
  while (!q.empty()) {
    int curX = q.front().first;
    int t = q.front().second;
    visited[curX] = true;
    q.pop();

    if (endTime < t) {
      break;
    } else if (curX == k) {
      endTime = t;
      ans++;
    } else {
      if (!visited[curX + 1] && curX < k) {
        q.push(make_pair(curX + 1, t + 1));
      }
      if (!visited[curX * 2] && curX < k) {
        q.push(make_pair(curX * 2, t + 1));
      }
      if (!visited[curX - 1] && curX > 0) {
        q.push(make_pair(curX - 1, t + 1));
      }
    }
  }

  cout << endTime << "\n" << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n >> k;
  solve();
}

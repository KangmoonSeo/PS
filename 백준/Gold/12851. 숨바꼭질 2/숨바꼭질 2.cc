#include <bits/stdc++.h>
using namespace std;

int n, k;

void solve() {
  bool visited[133334] = {};
  int ans = 0;
  int endTime = 100001;

  queue<pair<int, int> > q;
  q.push(make_pair(n, 0));
  visited[n] = true;

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
      if (curX < k && !visited[curX + 1]) {
        q.push(make_pair(curX + 1, t + 1));
      }
      if (curX < 66667 && !visited[curX * 2]) {
        q.push(make_pair(curX * 2, t + 1));
      }
      if (curX >= 1 && !visited[curX - 1]) {
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

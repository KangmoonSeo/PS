#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, k;
bool visited[200001] = {};
void push_zero(int cnt, int x,
               priority_queue<pii, vector<pii>, greater<pii> >& q) {
  int nx = x * 2;
  if (nx <= 200000 && !visited[nx]) {
    visited[nx] = true;
    q.push(make_pair(cnt, nx));
    push_zero(cnt, nx, q);
  }
}
void solve() {
  int ans = 0;
  priority_queue<pii, vector<pii>, greater<pii> > q;
  q.push(make_pair(0, n));
  visited[n] = true;
  while (!q.empty()) {
    int cnt = q.top().first;
    int x = q.top().second;

    q.pop();
    // termination
    if (x == k) {
      ans = cnt;
      break;
    }
    push_zero(cnt, x, q);
    int nx;
    nx = x - 1;  // x-1 (1s)
    if (nx >= 0 && nx <= 200000 && !visited[nx]) {
      visited[nx] = true;
      q.push(make_pair(cnt + 1, nx));
    }

    nx = x + 1;  // x+1 (1s)
    if (nx >= 0 && nx <= 200000 && !visited[nx]) {
      visited[nx] = true;
      q.push(make_pair(cnt + 1, nx));
    }
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n >> k;
  solve();
}

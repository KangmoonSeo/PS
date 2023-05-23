#include <bits/stdc++.h>
#define place first
#define count second
using namespace std;
typedef pair<int, int> pii;

vector<int> w(101, 0);
bool visited[101] = {};
int n, m;

void solve() {
  int ans = 100;
  queue<pii> q;
  q.push(make_pair(1, 0));
  visited[1] = true;
  while (!q.empty()) {
    int x = q.front().place;
    int cnt = q.front().count;
    q.pop();
    if (x == 100) {
      ans = cnt;
      break;
    }
    for (int i = 1; i <= 6; i++) {
      if (x + i > 100) break;
      int nxt = w[x + i];
      if (!visited[nxt]) {
        visited[x + i] = true;
        visited[nxt] = true;
        q.push(make_pair(nxt, cnt + 1));
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n >> m;
  int i1, i2;
  for (int i = 0; i <= 100; i++) {
    w[i] = i;
  }
  for (int i = 0; i < n + m; i++) {
    cin >> i1 >> i2;
    w[i1] = i2;
  }

  solve();
}

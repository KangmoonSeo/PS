#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n1, n2;
  bool visited[10001] = {};
  string ans = "";

  cin >> n1 >> n2;

  // bfs
  queue<pair<int, string> > q;
  q.push(make_pair(n1, ""));
  visited[n1] = true;
  while (!q.empty()) {
    pair<int, string> p = q.front();
    q.pop();

    int nxt[4];
    nxt[0] = (p.first * 2) % 10000;               // D
    nxt[1] = (p.first + 9999) % 10000;            // S
    nxt[2] = ((p.first * 10001) / 1000) % 10000;  // L 12341 ->2341
    nxt[3] = ((p.first * 10001) / 10) % 10000;    // R 41234 -> 1234
    char nxt_c[4] = {'D', 'S', 'L', 'R'};

    for (int i = 0; i < 4; i++) {
      if (nxt[i] == n2) {  // termination
        q = queue<pair<int, string> >();
        ans = p.second + nxt_c[i];
        break;
      }
      if (!visited[nxt[i]]) {
        visited[nxt[i]] = true;
        q.push(make_pair(nxt[i], p.second + nxt_c[i]));
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}

#include <bits/stdc++.h>
using namespace std;
#define a first
#define t second
typedef pair<int, int> pii;
int n;
vector<pii> tasks;
void solve() {
  int fl;
  pii cur = {0, 0}, nxt = {0, 0};

  int ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> fl;
    if (fl > 0) {
      cin >> nxt.a >> nxt.t;
      tasks.push_back(cur);  // 하던 과제 내려놓기
      cur = nxt;
    }
    cur.t--;
    if (cur.t <= 0) {
      ans += cur.a;
      if (tasks.empty()) {
        cur = {0, 0};
      } else {
        cur = tasks.back();
        tasks.pop_back();
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n;

  solve();
}

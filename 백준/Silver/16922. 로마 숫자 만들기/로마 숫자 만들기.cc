#include <bits/stdc++.h>
using namespace std;

int n;
const int roma[4] = {1, 5, 10, 50};
bool visited[1001] = {};

int ans = 0;
int sum = 0;

void BT(int v = 0, int init = 0) {
  if (v == n) {
    if (!visited[sum]) {
      visited[sum] = true;
      ans++;
    }
    return;
  }
  for (int i = init; i < 4; i++) {
    sum += roma[i];
    BT(v + 1, i);
    sum -= roma[i];
  }
}
void solve() {
  BT();
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n;
  solve();
}

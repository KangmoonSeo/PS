#include <bits/stdc++.h>
using namespace std;

string str;
vector<unordered_map<string, int>> visited;

int n, len, maxi;
void validate() {
  int cur = stoi(str);
  maxi = max(maxi, cur);
}
void BT(int TTL = 0) {
  if (visited[TTL][str] > 0) return;
  visited[TTL][str] = 1;

  if (TTL == n) {
    validate();
    return;
  }
  for (int u = 0; u < len; u++) {
    for (int v = u + 1; v < len; v++) {
      swap(str[u], str[v]);
      BT(TTL + 1);
      swap(str[u], str[v]);
    }
  }
}
void solve() {
  maxi = 0;
  len = str.size();
  visited = vector<unordered_map<string, int>>(11);
  BT(0);
  cout << maxi << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  int test_case;
  cin >> test_case;
  for (int t = 1; t <= test_case; t++) {
    cin >> str >> n;

    cout << "#" << t << " ";
    solve();
  }
}

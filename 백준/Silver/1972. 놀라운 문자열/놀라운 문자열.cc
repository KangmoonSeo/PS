#include <bits/stdc++.h>
using namespace std;

string str;

void solve() {
  bool visited[27][27];
  int length = str.size();
  bool isAns = true;
  for (int D = 1; D < length - 1; D++) {
    fill_n(visited[0], 27 * 27, false);
    for (int i = 0; i < length - D; i++) {
      int u = str[i] - 'A';
      int v = str[i + D] - 'A';
      if (visited[u][v]) isAns = false;
      visited[u][v] = true;
      if (!isAns) break;
    }
    if (!isAns) break;
  }

  cout << str << " is " << (isAns ? "" : "NOT ") << "surprising.\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> str;
  while (str != "*") {
    solve();
    cin >> str;
  }
}

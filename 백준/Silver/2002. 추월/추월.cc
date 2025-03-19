#include <bits/stdc++.h>
using namespace std;

int n;

unordered_map<string, int> _str_to_num;

int solve() {
  // function works here
  queue<string> in_q;
  int ans = 0;
  string input;

  for (int i = 0; i < n; i++) {
    cin >> input;
    in_q.push(input);
  }
  queue<string> out_q;

  for (int i = 0; i < n; i++) {
    cin >> input;
    out_q.push(input);
  }

  unordered_map<string, int> trash_bin;
  int cnt = 0;
  while (!in_q.empty()) {
    string in_s = in_q.front();
    in_q.pop();
    cnt++;

    if (trash_bin[in_s] > 0) continue;

    while (!out_q.empty()) {
      string out_s = out_q.front();
      out_q.pop();
      if (in_s == out_s) {
        break;
      } else {
        trash_bin[out_s] = 1;
        ans++;
      }
    }
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n;
  int ans = solve();
  cout << ans << "\n";
}

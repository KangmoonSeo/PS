#include <bits/stdc++.h>
using namespace std;

string n;
bool visited[30] = {};
void solve() {
  string input;
  getline(cin, input);

  int length = input.size();
  bool isBraced = false;
  bool isReady = true;
  string ans = "";
  for (int i = 0; i < length; i++) {
    ans += '[';
    int c = input[i] >= 'a' ? input[i] - 'a' : input[i] - 'A';
    if (input[i] != ' ' && isReady && !visited[c] && !isBraced) {
      isBraced = true;
      visited[c] = true;
      ans += input[i];
      ans += ']';
    } else {
      isReady = (input[i] == ' ');
      ans.pop_back();
      ans += input[i];
    }
  }
  if (isBraced) {
    cout << ans << "\n";
    return;
  }
  // 2회차
  ans = "";
  for (int i = 0; i < length; i++) {
    ans += '[';
    int c = input[i] >= 'a' ? input[i] - 'a' : input[i] - 'A';
    if (input[i] != ' ' && !visited[c] && !isBraced) {
      isBraced = true;
      visited[c] = true;
      ans += input[i];
      ans += ']';
    } else {
      ans.pop_back();
      ans += input[i];
    }
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  getline(cin, n);
  int T = stoi(n);
  while (T--) {
    solve();
  }
}

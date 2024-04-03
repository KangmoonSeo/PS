#include <bits/stdc++.h>
using namespace std;

int k;

vector<string> vec;           // 4개의 톱니 칼, 0:N극, 1:S극
vector<pair<int, int> > rot;  // first: 톱니 번호, second: 1=시계, -1=반시계

bool visited[4] = {};

void rotate_wheel(int number, int dir) {
  int nxt = number + 1;
  if (nxt < 4 && !visited[nxt]) {
    visited[nxt] = true;

    if (vec[number][2] != vec[nxt][6]) rotate_wheel(nxt, -1 * dir);
  }

  int prev = number - 1;
  if (prev >= 0 && !visited[prev]) {
    visited[prev] = true;

    if (vec[prev][2] != vec[number][6]) rotate_wheel(prev, -1 * dir);
  }

  string new_vec = "";
  new_vec += vec[number][7];
  new_vec += vec[number];
  new_vec += vec[number][0];

  vec[number] = "";

  int start = (dir > 0) ? 0 : 2;

  for (int i = start; i < start + 8; i++) {
    vec[number].push_back(new_vec[i]);
  }
}

void solve() {
  for (auto p : rot) {
    fill_n(visited, 4, false);
    visited[p.first] = true;
    rotate_wheel(p.first, p.second);
  }

  int ans = 0;
  if (vec[0][0] > '0') ans += 1;
  if (vec[1][0] > '0') ans += 2;
  if (vec[2][0] > '0') ans += 4;
  if (vec[3][0] > '0') ans += 8;

  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  string str;

  for (int i = 0; i < 4; i++) {
    cin >> str;
    vec.push_back(str);
  }

  cin >> k;
  int p1, p2;
  for (int i = 0; i < k; i++) {
    cin >> p1 >> p2;
    p1--;
    rot.push_back({p1, p2});
  }

  solve();
}

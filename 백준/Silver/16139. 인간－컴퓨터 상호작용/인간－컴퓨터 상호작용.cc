#include <bits/stdc++.h>
using namespace std;

void solve() {
  string str;
  cin >> str;
  // 누적합 전처리
  vector<vector<int> > m(200001, vector<int>('z' - 'a' + 1));
  int length = str.size();

  m[0][str[0] - 'a']++;
  for (int i = 1; i <= length; i++) {
    char t = str[i] - 'a';

    for (int j = 0; j <= 'z' - 'a'; j++) {
      m[i][j] = m[i - 1][j];
      if (t == j) m[i][j]++;
    }
  }

  int q;
  cin >> q;
  char c1;
  int i2, i3;
  while (q--) {
    cin >> c1 >> i2 >> i3;
    c1 -= 'a';
    if (i2 == 0)
      cout << m[i3][c1] << "\n";
    else
      cout << m[i3][c1] - m[i2 - 1][c1] << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  solve();
}

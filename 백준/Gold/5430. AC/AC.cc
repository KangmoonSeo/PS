#include <bits/stdc++.h>
using namespace std;

int T;

void solve() {
  // input
  string s1, s3;
  int i2;
  cin >> s1 >> i2 >> s3;
  vector<int> deq;

  string buf;
  for (int i = 0; i < s3.size(); i++) {
    if (s3[i] == '[')
      continue;
    else if (s3[i] == ',' || s3[i] == ']') {
      if (buf != "") deq.push_back(stoi(buf));
      buf = "";
    } else {
      buf += s3[i];
    }
  }

  int cnt_f = 0, cnt_b = 0;
  bool isReverse = false;
  for (int i = 0; i < s1.size(); i++) {
    if (s1[i] == 'R')
      isReverse = !isReverse;
    else {
      if (!isReverse)
        cnt_f++;
      else
        cnt_b++;
    }
  }

  // answer

  if (cnt_f + cnt_b > i2) {
    cout << "error\n";
  } else {
    cout << "[";
    if (isReverse) {
      for (int i = i2 - cnt_b - 1; i >= cnt_f; i--) {
        cout << deq[i];
        if (i > cnt_f) cout << ",";
      }
    } else {
      for (int i = cnt_f; i <= i2 - cnt_b - 1; i++) {
        cout << deq[i];
        if (i < i2 - cnt_b - 1) cout << ",";
      }
    }
    cout << "]\n";
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> T;
  while (T--) {
    solve();
  }
}

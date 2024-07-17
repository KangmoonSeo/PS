#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<vector<int>> generate_sequences(int num = 0) {
  vector<vector<int>> ret;

  if (num == 1) {
    for (int i = 1; i <= m; ++i) {
      ret.push_back({i});
    }
    return ret;
  }

  auto prev_sequences = generate_sequences(num - 1);  // recursive

  for (auto seq : prev_sequences) {
    int init = seq.back();

    for (int i = init + 1; i <= m; ++i) {
      vector<int> new_seq = seq;
      new_seq.push_back(i);
      ret.push_back(new_seq);
    }
  }

  return ret;
}

void solve() {
  bitset<11> solves[11];

  for (int i = 1; i <= m; i++) {
    int input;
    cin >> input;

    while (input--) {
      int val;
      cin >> val;
      solves[i][val] = 0b1;
    }
  }

  bitset<11> answer;  // 원본 정답
  for (int i = 1; i <= n; i++) {
    answer[i] = 0b1;
  }

  vector<vector<int>> sequences = generate_sequences(m);

  for (int i = 1; i <= m; i++) {
    auto sequences = generate_sequences(i);  // sequence: [ [1,2], [1,3], ... ]

    for (vector<int> sequence : sequences) {
      bitset<11> cur;

      for (int idx : sequence) {
        auto bitset = solves[idx];
        cur |= bitset;
      }

      if (cur == answer) {
        cout << i << "\n";
        return;
      }
    }
  }

  cout << "-1\n";
  return;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n >> m;
  solve();
}

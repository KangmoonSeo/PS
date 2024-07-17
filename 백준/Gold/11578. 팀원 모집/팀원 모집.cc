#include <bits/stdc++.h>
using namespace std;

int n, m;
bitset<11> solves[11];
bitset<11> answer;

vector<vector<int>> generate_sequences(int num = 0) {
  vector<vector<int>> result;

  if (num == 1) {
    for (int i = 1; i <= m; ++i) {
      result.push_back({i});
    }
    return result;
  }

  // 재귀적으로 num-1 길이의 시퀀스 생성
  auto prev_sequences = generate_sequences(num - 1);

  // 각 이전 시퀀스에 대해 새로운 숫자 추가
  for (const auto seq : prev_sequences) {
    int last = seq.back();
    for (int i = last + 1; i <= m; ++i) {
      vector<int> new_seq = seq;
      new_seq.push_back(i);
      result.push_back(new_seq);
    }
  }

  return result;
}

void solve() {
  for (int i = 1; i <= n; i++) {
    answer[i] = 0b1;
  }

  for (int i = 1; i <= m; i++) {
    int input;
    cin >> input;

    while (input--) {
      int val;
      cin >> val;
      solves[i][val] = 0b1;
    }
  }

  vector<vector<int>> sequences = generate_sequences(m);

  for (int i = 1; i <= m; i++) {
    auto sequences = generate_sequences(i);  // sequence : [ [1,2], [1,3], ... ]

    for (auto sequence : sequences) {
      // sequence : [1,2]
      bitset<11> cur;

      for (auto idx : sequence) {
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

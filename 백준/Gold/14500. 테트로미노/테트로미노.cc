#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 실행속도 최적화 end

  int n, m;  // input
  cin >> n >> m;

  vector<vector<int>> ar(n + 6, vector<int>(m + 6));

  for (size_t i = 3; i < n + 3; i++) {
    for (size_t j = 3; j < m + 3; j++) {
      cin >> ar[i][j];
    }
  }
  int rs = 0;
  // brute force algorithm, (i,j)->(0->n,0->m) 모든 케이스 시행 후 최대값 출력
  for (size_t i = 3; i < n + 3; i++) {
    for (size_t j = 3; j < m + 3; j++) {
      // 1. I 블럭
      rs = max(rs, (ar[i][j] + ar[i + 1][j] + ar[i + 2][j] + ar[i + 3][j]));
      rs = max(rs, (ar[i][j] + ar[i][j + 1] + ar[i][j + 2] + ar[i][j + 3]));
      // 2. O 블럭
      rs = max(rs, (ar[i][j] + ar[i + 1][j] + ar[i][j + 1] + ar[i + 1][j + 1]));
      // 3. T 블럭
      rs = max(rs, (ar[i][j] + ar[i + 1][j] + ar[i + 2][j] + ar[i + 1][j + 1]));
      rs = max(rs, (ar[i][j] + ar[i + 1][j] + ar[i + 2][j] + ar[i + 1][j - 1]));
      rs = max(rs, (ar[i][j] + ar[i][j + 1] + ar[i][j + 2] + ar[i + 1][j + 1]));
      rs = max(rs, (ar[i][j] + ar[i][j + 1] + ar[i][j + 2] + ar[i - 1][j + 1]));
      // 4. S,Z 블럭
      rs = max(rs,
               (ar[i][j] + ar[i + 1][j] + ar[i + 1][j + 1] + ar[i + 2][j + 1]));
      rs = max(rs,
               (ar[i][j] + ar[i + 1][j] + ar[i + 1][j - 1] + ar[i + 2][j - 1]));
      rs = max(rs,
               (ar[i][j] + ar[i][j + 1] + ar[i + 1][j + 1] + ar[i + 1][j + 2]));
      rs = max(rs,
               (ar[i][j] + ar[i][j + 1] + ar[i - 1][j + 1] + ar[i - 1][j + 2]));
      // 5. L,J 블럭
      rs = max(rs, (ar[i][j] + ar[i + 1][j] + ar[i + 2][j] + ar[i + 2][j + 1]));
      rs = max(rs, (ar[i][j] + ar[i + 1][j] + ar[i + 2][j] + ar[i + 2][j - 1]));
      rs = max(rs, (ar[i][j] + ar[i + 1][j] + ar[i + 2][j] + ar[i][j + 1]));
      rs = max(rs, (ar[i][j] + ar[i + 1][j] + ar[i + 2][j] + ar[i][j - 1]));
      rs = max(rs, (ar[i][j] + ar[i][j + 1] + ar[i][j + 2] + ar[i + 1][j + 2]));
      rs = max(rs, (ar[i][j] + ar[i][j + 1] + ar[i][j + 2] + ar[i - 1][j + 2]));
      rs = max(rs, (ar[i][j] + ar[i][j + 1] + ar[i][j + 2] + ar[i + 1][j]));
      rs = max(rs, (ar[i][j] + ar[i][j + 1] + ar[i][j + 2] + ar[i - 1][j]));
    }
  }
  cout << rs << endl;  // output
}

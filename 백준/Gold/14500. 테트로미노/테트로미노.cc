#include <algorithm>
#include <cmath>
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

  vector<vector<int>> ar(n + 6, vector<int>(m + 6));  // output

  for (size_t i = 3; i < n + 3; i++) {
    for (size_t j = 3; j < m + 3; j++) {
      cin >> ar[i][j];
    }
  }
  int rs = 0;
  // brute force algorithm, (i,j)->(0->n,0->m) 모든 케이스 시행 후 최대값 출력
  for (size_t i = 3; i < n + 3; i++) {
    for (size_t j = 3; j < m + 3; j++) {
      // 4x1
      rs = max(rs, (ar[i][j] + ar[i + 1][j] + ar[i + 2][j] + ar[i + 3][j]));
      rs = max(rs, (ar[i][j] + ar[i][j + 1] + ar[i][j + 2] + ar[i][j + 3]));
      // 2x2
      rs = max(rs, (ar[i][j] + ar[i + 1][j] + ar[i][j + 1] + ar[i + 1][j + 1]));
      // ㅏ
      rs = max(rs, (ar[i][j] + ar[i + 1][j] + ar[i + 2][j] + ar[i + 1][j + 1]));
      rs = max(rs, (ar[i][j] + ar[i + 1][j] + ar[i + 2][j] + ar[i + 1][j - 1]));
      rs = max(rs, (ar[i][j] + ar[i][j + 1] + ar[i][j + 2] + ar[i + 1][j + 1]));
      rs = max(rs, (ar[i][j] + ar[i][j + 1] + ar[i][j + 2] + ar[i - 1][j + 1]));
      // '--,
      rs = max(rs,
               (ar[i][j] + ar[i + 1][j] + ar[i + 1][j + 1] + ar[i + 2][j + 1]));
      rs = max(rs,
               (ar[i][j] + ar[i + 1][j] + ar[i + 1][j - 1] + ar[i + 2][j - 1]));
      rs = max(rs,
               (ar[i][j] + ar[i][j + 1] + ar[i + 1][j + 1] + ar[i + 1][j + 2]));
      rs = max(rs,
               (ar[i][j] + ar[i][j + 1] + ar[i - 1][j + 1] + ar[i - 1][j + 2]));
      // ㄴ
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
  cout << rs << endl;
}

/*

      rs = max({rs, (ar[i][j] + ar[i + 1][j] + ar[i + 2][j] +
                             ar[i + 3][j])});
      // (0,0 1,0 2,0 2,1) L
      rs = max({rs, (ar[i][j] + ar[i + 1][j] + ar[i + 2][j] +
                             ar[i + 2][j + 1])});
      // (0,0 1,0 1,1 2,0) ㅏ
      rs = max({rs, (ar[i][j] + ar[i + 1][j] + ar[i + 1][j + 1] +
                             ar[i + 2][j])});
      // (0,0 1,0 1,1 2,1)
      rs = max({rs, (ar[i][j] + ar[i + 1][j] + ar[i + 1][j + 1] +
                             ar[i + 2][j + 1])});
      // (0,0 1,0 1,1 1,2) ㄴ
      rs = max({rs, (ar[i][j] + ar[i + 1][j] + ar[i + 1][j + 1] +
                             ar[i + 1][j + 2])});

      // 2. (0,1) max -> (0,0 0,1 1,1 1,0),
      rs = max({rs, (ar[i][j] + ar[i][j + 1] + ar[i + 1][j + 1] +
                             ar[i + 1][j])});
      // (0,0 0,1 1,1 2,1),
      rs = max({rs, (ar[i][j] + ar[i][j + 1] + ar[i + 1][j + 1] +
                             ar[i + 2][j + 1])});
      // (0,0 0,1 1,1 1,2)
      rs = max({rs, (ar[i][j] + ar[i][j + 1] + ar[i + 1][j + 1] +
                             ar[i + 1][j + 2])});

      // 3. (0,2) max -> (0,0 0,1 0,2 1,2)
      rs = max({rs, (ar[i][j] + ar[i][j + 1] + ar[i][j + 2] +
                             ar[i + 1][j + 2])});
      // (0,0 0,1 0,2 1,1)
      rs = max({rs, (ar[i][j] + ar[i][j + 1] + ar[i][j + 2] +
                             ar[i + 1][j + 1])});
      // (0,0 0,1 0,2 1,0)
      rs = max({rs, (ar[i][j] + ar[i][j + 1] + ar[i][j + 2] +
                             ar[i + 1][j])});

      // 4. (0,3) max -> (0,0 0,1 0,2 0,3)
      rs = max({rs, (ar[i][j] + ar[i][j + 1] + ar[i][j + 2] +
                             ar[i][j + 3])});

*/
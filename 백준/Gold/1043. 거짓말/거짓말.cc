#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int n, m, t1, p1;
set<int> t2;
vector<vector<int> > p2;

bool integrity_check(int input, bool isExist) {
  if (isExist) return true;
  for (int it : t2) {
    if (input == it) return true;
  }
  return false;
}

void solve() {
  int len1 = p2.size();
  for (int i = 0; i < len1; i++) {  // n < 50 -> loop 개수 상관 X
    int len2 = p2[i].size();
    for (int j = 0; j < len2; j++) {
      for (int it : t2) {
        if (p2[i][j] == it) {  // delete p2[i] and recur
          for (int k = 0; k < len2; k++) {
            t2.insert(p2[i][k]);  // insert p2[i] into t2
          }
          p2.erase(p2.begin() + i);  // delete p2[i]
          solve();                   // recur
          return;
        }
      }
    }
  }
  cout << len1 << "\n";
}

int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  // 실행속도 최적화 end

  cin >> n >> m;
  cin >> t1;
  if (t1 != 0) {
    int input;
    for (int i = 0; i < t1; i++) {
      cin >> input;
      t2.insert(input);
    }
  }
  while (m--) {
    cin >> p1;
    vector<int> tmp;
    int input;
    bool isExist = false;
    for (int i = 0; i < p1; i++) {
      cin >> input;
      isExist = integrity_check(input, isExist);
      tmp.push_back(input);
    }
    if (isExist) {  // union into t2 and skip push
      for (int i = 0; i < p1; i++) {
        t2.insert(tmp[i]);
      }
    } else {
      p2.push_back(tmp);
    }
  }
  solve();
}

#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;

void DPQ() {
  int k;
  cin >> k;
  multiset<int> mset;

  while (k--) {
    char i1;
    int i2;
    cin >> i1 >> i2;
    if (i1 == 'I') {  // insert
      mset.insert(i2);
    } else if (!mset.empty() && i2 == -1) {  // pop min
      mset.erase(mset.begin());
    } else if (!mset.empty() && i2 == 1) {  // pop max
      mset.erase(--mset.end());
    }
  }
  if (mset.empty()) {
    cout << "EMPTY\n";
  } else {
    cout << *(--mset.end()) << " " << *(mset.begin()) << "\n";
  }
}
int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 실행속도 최적화 end

  int T;  // input
  cin >> T;
  while (T--) {
    DPQ();
  }
}

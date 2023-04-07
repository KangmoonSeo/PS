#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void func(int n, vector<vector<int> > arr, int col, int row) {
  int len = n / 2;

  int color = arr[col][row];
  bool isDominent = true;

  for (int i = col; i < col + n; i++) {
    for (int j = row; j < row + n; j++) {
      if (color != arr[i][j]) {
        isDominent = false;
        break;
      }
    }
  }
  if (isDominent) {
    cout << color;
  } else {
    cout << "(";
    func(len, arr, col, row);
    func(len, arr, col, row + len);
    func(len, arr, col + len, row);
    func(len, arr, col + len, row + len);
    cout << ")";
  }
}

int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 실행속도 최적화 end

  int n;  // input
  cin >> n;
  vector<vector<int> > arr(n, vector<int>(n));
  string tmpstr = "";
  for (int i = 0; i < n; i++) {
    cin >> tmpstr;
    for (int j = 0; j < n; j++) {
      arr[i][j] = tmpstr[j] - 48;
    }
  }
  func(n, arr, 0, 0);
}

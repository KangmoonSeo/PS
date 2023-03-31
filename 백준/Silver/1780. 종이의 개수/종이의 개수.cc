#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int arr[2187][2187];
int stack[3] = {0, 0, 0};

void addStack(int val) { stack[val + 1]++; }  // -1 -> stack[0]++, ...

void crop(int num, int row, int col) {
  int tmp = arr[row][col];
  bool cropFlag = false;

  if (num <= 1) {
    addStack(tmp);
    return;
  }
  for (int i = row; i < row + num; i++) {
    for (int j = col; j < col + num; j++) {
      if (tmp != arr[i][j]) {
        cropFlag = true;
        break;
      }
      tmp = arr[i][j];
    }
  }
  // 종이를 잘라야 하는 경우
  if (cropFlag) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        crop(num / 3, row + i * (num / 3), col + j * (num / 3));
      }
    }
  } else {  // 종이를 그냥 두는 경우
    addStack(tmp);
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

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }
  crop(n, 0, 0);
  cout << stack[0] << "\n" << stack[1] << "\n" << stack[2];
}

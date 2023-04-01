#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
#define L_MAX 128

int arr[L_MAX][L_MAX];
int cnt[2] = {0, 0};

void crop(int num, int row, int col) {
  int tmp = arr[row][col];
  bool cropFlag = false;

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
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++)
        crop(num / 2, row + i * (num / 2), col + j * (num / 2));

  } else {  // 종이를 그냥 두는 경우
    cnt[tmp]++;
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
  cout << cnt[0] << "\n" << cnt[1];
}

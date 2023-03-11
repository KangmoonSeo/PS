#include <iostream>
using namespace std;

void NandM(int max, int len) {
  // 0. mem 초기화(1,2,3, ...)
  int* mem = new int[len]();
  for (int i = 0; i < len; i++) mem[i] = 1 + i;

  while (mem[0] < max - len + 2) {
    // 1. 현재 mem 출력
    for (int i = 0; i < len; i++) cout << mem[i] << " ";
    cout << "\n";

    // 2. mem 마지막 자리 1 가산
    mem[len - 1]++;

    // 3. 값 조작 및 종결 조건 확인
    for (int i = 0; i < len; i++) {
      int _point = len - i - 1;

      if (mem[_point] > max - i) {  // 현 memory의 허용치(max-i)를 초과하면
        if (_point == 0) return;  // (종결) mem[0]에서 초과하면 함수 종료
        mem[_point - 1]++;        // 왼쪽 메모리 가산
        for (int j = _point; j < len; j++) {
          mem[j] = mem[j - 1] + 1;  // 왼쪽 메모리 복사
        }
      }
    }
  }
}

int main() {
  int n, m;  // input
  cin >> n >> m;

  NandM(n, m);  // output
}
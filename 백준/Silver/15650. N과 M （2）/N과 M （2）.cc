#include <iostream>
using namespace std;

void NandM(int max, int len) {
  // mem 초기화(1,2,3, ...)
  int* mem = new int[len]();
  for (size_t i = 0; i < len; i++) {
    mem[i] = 1 + i;
  }

  while (true) {
    // 1. 현재 mem 출력
    for (size_t i = 0; i < len; i++) cout << mem[i] << " ";
    cout << "\n";

    mem[len - 1]++;  // 2. mem 마지막 자리 1 가산

    // 3. 값 조작 및 종결 조건 확인
    for (size_t i = 0; i < len; i++) {  // 0, 1, ... , len-1
      int _current = len - i - 1;       // len-1, len-2, ... , 0

      if (mem[_current] > max - i) {  // 현 memory의 허용치(max-i)를 초과하면
        if (_current == 0) return;  // (종결) mem[0]에서 초과하면 함수 종료
        mem[_current - 1]++;  // 전단계 메모리 가산
        for (size_t j = _current; j < len; j++) {
          mem[j] = mem[j - 1] + 1;  // 전단계 메모리의 값 copy
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
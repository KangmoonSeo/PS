#include <iostream>
using namespace std;

int* findPrime(int, int);
bool isPrime(int);
// 자연수 M과 N이 주어질 때, M이상 N이하의 자연수 중 소수인 것을 모두 골라
// 이들 소수의 합과 최솟값을 찾는 프로그램
int* findPrime(int min, int max) {
  int* result = new int[2]{0, 0};
  int sum = 0;
  bool flag = false;

  for (size_t i = min; i <= max; i++) {
    if (!isPrime(i)) continue;
    if (!flag) {
      result[1] = i;
      flag = true;
    }
    sum += i;
  }
  result[0] = sum;

  return result;
}

bool isPrime(int num) {  // Def 소수: 1과 자기 자신만을 약수로 가지는 수,
  if (num < 2) return false;
  for (size_t i = 2; i < num; i++) {  // O(n)
    if (num % i == 0) return false;
  }
  return true;
}

int main() {
  int n, m;  // input
  cin >> n >> m;

  int* result = findPrime(n, m);  // output

  if (result[0] == 0) {
    cout << "-1";
  } else {
    cout << result[0] << "\n" << result[1];
  }
}
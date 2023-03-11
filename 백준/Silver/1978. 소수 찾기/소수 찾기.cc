#include <iostream>
using namespace std;

bool isPrime(int num) {  // Def 소수: 1과 자기 자신만을 약수로 가지는 수
  if (num < 2) return false;

  for (size_t i = 2; i < num; i++) {  // O(n)
    if (num % i == 0) return false;
  }
  return true;
}

int main() {
  int n;  // input
  cin >> n;

  int* arr = new int[n]();
  for (size_t i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int result = 0;  // output

  for (size_t i = 0; i < n; i++) {
    result += (int)isPrime(arr[i]);
  }
  cout << result;
}
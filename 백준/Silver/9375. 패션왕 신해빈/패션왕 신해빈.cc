#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

void wear() {
  int n;
  string s1, s2;
  unordered_map<string, int> arr;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s1 >> s2;
    arr[s2]++;
  }
  int result = 1;
  for (unordered_map<string, int>::iterator iter = arr.begin();
       iter != arr.end(); iter++) {
    result *= (iter->second + 1);
  }
  result--;
  cout << result << "\n";
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
    wear();
  }
}

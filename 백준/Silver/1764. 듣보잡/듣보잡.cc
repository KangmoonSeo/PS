#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;

int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 실행속도 최적화 end

  int n, m;  // input
  cin >> n >> m;

  map<string, bool> arr;
  vector<string> result;
  string input;

  for (int i = 0; i < n + m; i++) {
    cin >> input;
    if (arr[input]) result.push_back(input);
    arr[input] = true;
  }
  sort(result.begin(), result.end());
  int length = result.size();
  cout << length << "\n";
  for (int i = 0; i < length; i++) {
    cout << result[i] << "\n";
  }
}

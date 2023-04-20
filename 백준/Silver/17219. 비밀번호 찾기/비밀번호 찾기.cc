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

  map<string, string> arr;
  string a, b;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    arr[a] = b;
  }
  for (int i = 0; i < m; i++) {
    cin >> a;
    cout << arr[a] << "\n";
  }
}

#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <string>
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
  string s_input;
  
  unordered_map<string, int> i_data;
  vector<string> s_data(n + 1);

  for (int i = 1; i <= n; i++) {
    cin >> s_input;
    i_data[s_input] = i;
    s_data[i] = s_input;
  } 

  for (int j = 0; j < m; j++) {
    cin >> s_input;
    if (!isdigit(s_input[0])) {  // string
      cout << i_data[s_input] << "\n";
    } else {  // int
      cout << s_data[stoi(s_input)] << "\n";
    }
  }
}

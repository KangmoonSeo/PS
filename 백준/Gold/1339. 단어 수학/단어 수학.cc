#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> arr;
map<char, int> m;
void solve() {
  int len_arr = arr.size();
  for (int i = 0; i < len_arr; i++) {
    string str = arr[i];
    int len_str = str.size();
    for (int j = 1; j <= len_str; j++) {
      m[str[len_str - j]] += pow(10, j - 1);
    }
  }
  int i_max;
  char c_max;
  int sum = 0;
  int j = 9;
  while (!m.empty()) {
    i_max = 0;
    for (auto it : m) {
      if (it.second > i_max) {
        i_max = it.second;
        c_max = it.first;
      }
    }
    sum += j * i_max;
    m.erase(c_max);
    j--;
  }
  cout << sum << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  int n;  // input
  cin >> n;
  arr.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  solve();
}

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, m;
vector<pii> vec;

void solve() {
  // function works here
  string str;
  int tablenum, t;
  while (n--) {
    cin >> str;
    if (str == "sort") {
      sort(vec.begin(), vec.end());
    } else if (str == "order") {
      cin >> tablenum >> t;
      vec.push_back({t, tablenum});
    } else if (str == "complete") {
      cin >> tablenum;
      bool isFind = false;
      for (int i = 0; i < vec.size(); i++) {
        if (isFind) {
          vec[i - 1] = vec[i];
        }
        if (vec[i].second == tablenum) {
          isFind = true;
        }
      }
      vec.pop_back();
    }
    if (vec.empty()) {
      cout << "sleep\n";
    } else {
      for (int i = 0; i < vec.size(); i++) {
        cout << vec[i].second << " ";
      }
      cout << "\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n >> m;
  solve();
}

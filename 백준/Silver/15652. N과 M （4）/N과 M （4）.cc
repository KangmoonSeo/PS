#include <bits/stdc++.h>
using namespace std;

int n, m;  // input

void recur(vector<int> st, int TTL) {
  vector<int> tmp = st;

  for (int i = st.back(); i <= n; i++) {
    if (TTL == 0) {
      for (int j = 0; j < tmp.size(); j++) {
        cout << tmp[j] << " ";
      }
      cout << i << "\n";
    } else {
      tmp.push_back(i);
      recur(tmp, TTL - 1);
      tmp.pop_back();
    }
  }
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n >> m;
  vector<int> tmp;
  if (m < 2) {
    for (int i = 1; i <= n; i++) {
      cout << i << "\n";
    }
    return 0;
  }

  for (int i = 1; i <= n; i++) {
    tmp.clear();
    tmp.push_back(i);
    recur(tmp, m - 2);
  }
}

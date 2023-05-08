#include <bits/stdc++.h>
using namespace std;

int n, m;  // input
vector<int> arr;

void recur(int TTL) {
  if (TTL == 0) {
    int length = arr.size();
    for (int i = 0; i < length; i++) {
      cout << arr[i] << " ";
    }
    cout << "\n";
    return;
  }

  int b = arr.back();
  for (int i = b; i <= n; i++) {
    arr.push_back(i);
    recur(TTL - 1);
    arr.pop_back();
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    arr.push_back(i);
    recur(m - 1);
    arr.pop_back();
  }
}

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> field;
vector<int> bt;
map<int, int> bb;
void BT(int init = 0) {
  if (init == m) {
    int length = bt.size();
    for (int i = 0; i < length; i++) {
      cout << bt[i] << " ";
    }
    cout << "\n";
    return;
  }
  int b;
  if (bt.empty()) {
    b = 0;
  } else {
    b = bb[bt.back()];
  }
  for (int i = b; i < n; i++) {
    bt.push_back(field[i]);
    BT(init + 1);
    bt.pop_back();
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n >> m;
  int input;
  for (int i = 0; i < n; i++) {
    cin >> input;
    field.push_back(input);
  }
  sort(field.begin(), field.end());
  for (int i = 0; i < n; i++) {
    bb[field[i]] = i;
  }

  BT();
}

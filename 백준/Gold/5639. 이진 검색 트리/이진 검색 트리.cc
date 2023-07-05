#include <bits/stdc++.h>
using namespace std;

int tree[10001];
int treeSize = 0;

void post(int start, int end) {
  if (start >= end) return;
  if (start == end - 1) {
    cout << tree[start] << "\n";
    return;
  }
  int idx = start + 1;
  while (idx < end) {
    if (tree[start] < tree[idx]) break;
    idx++;
  }
  post(start + 1, idx);
  post(idx, end);
  cout << tree[start] << "\n";
}

void solve() {
  int input = 1;
  while (cin >> input) {
    tree[treeSize] = input;
    treeSize++;
  }
  post(0, treeSize);
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  solve();
}

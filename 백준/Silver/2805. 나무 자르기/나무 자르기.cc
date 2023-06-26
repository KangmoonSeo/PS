#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
ll tree[1000001];

void solve() {
  sort(tree, tree + n);  // O(NlogN)
  ll sum = 0, start = 0, end = tree[n - 1], mid, target = -1;
  while (start <= end) {
    sum = 0;
    mid = (start + end) / 2;
    for (int i = 0; i < n; i++) {
      if (tree[i] - mid > 0) sum += tree[i] - mid;
    }
    if (sum >= m) {
      start = mid + 1;
      if (mid > target) target = mid;
    } else {
      end = mid - 1;
    }
  }
  cout << target << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> tree[i];
  }
  solve();
}

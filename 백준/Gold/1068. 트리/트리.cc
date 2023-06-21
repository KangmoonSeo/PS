#include <bits/stdc++.h>
using namespace std;

int n;
int target;
vector<int> parent;  // parent[i] : parent of i-th node
bool visited[51] = {};

bool findRoot(int v) {
  if (parent[v] == -1) {
    return true;
  } else if (parent[v] == target) {
    return false;
  } else {
    return findRoot(parent[v]);
  }
}
void solve() {
  int untracted = 0;
  for (int i = 0; i < n; i++) {
    if (findRoot(i)) {
      if (parent[i] == -1 || i == target) continue;
      visited[parent[i]] = true;
    } else {
      untracted++;
    }
  }
  int ans = n;
  for (int i = 0; i < n; i++) {
    if (visited[i]) ans--;  // subtract parent node
  }
  ans -= 1;          // subtract target node
  ans -= untracted;  // subtract untracked node

  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n;
  int input;
  for (int i = 0; i < n; i++) {
    cin >> input;
    parent.push_back(input);
  }
  cin >> target;

  solve();
}

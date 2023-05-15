#include <bits/stdc++.h>
#define max(a, b) a > b ? a : b
#define min(a, b) a > b ? b : a
using namespace std;
int n;
bool visited[1000001] = {};

void solve() {
  queue<pair<int, vector<int> > > q;
  q.push(make_pair(n, vector<int>(1, n)));
  visited[n] = true;

  while (!q.empty()) {
    int val = q.front().first;
    vector<int> vec = q.front().second;
    q.pop();

    if (val == 1) {
      int len = vec.size();
      cout << len - 1 << "\n";
      for (int i = 0; i < len; i++) {
        cout << vec[i] << " ";
      }
      cout << "\n";
      break;
    }

    if (val % 3 == 0 && !visited[val / 3]) {
      visited[val / 3] = true;
      vec.push_back(val / 3);
      q.push(make_pair(val / 3, vec));
      vec.pop_back();
    }
    if (val % 2 == 0 && !visited[val / 2]) {
      visited[val / 2] = true;
      vec.push_back(val / 2);
      q.push(make_pair(val / 2, vec));
      vec.pop_back();
    }
    if (!visited[val - 1]) {
      visited[val - 1] = true;
      vec.push_back(val - 1);
      q.push(make_pair(val - 1, vec));
      vec.pop_back();
    }
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n;
  solve();
}

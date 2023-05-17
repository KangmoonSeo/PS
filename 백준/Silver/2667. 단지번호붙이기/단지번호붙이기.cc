#include <bits/stdc++.h>
using namespace std;
typedef map<pair<int, int>, int> mpi;
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};
int n;
bool arr[27][27] = {};
bool visited[27][27] = {};

mpi m;
void bfs(int y, int x, pair<int, int> p) {
  for (int d = 0; d < 4; d++) {
    int ny = y + dy[d];
    int nx = x + dx[d];
    if (arr[ny][nx] && !visited[ny][nx]) {
      visited[ny][nx] = true;
      m[p]++;
      bfs(ny, nx, p);
    }
  }
}
void numbering() {
  // input
  string input;
  for (int j = 1; j <= n; j++) {
    cin >> input;
    for (int i = 0; i < n; i++) {
      arr[j][i + 1] = input[i] - '0';
    }
  }
  // bfs
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= n; i++) {
      if (arr[j][i] && !visited[j][i]) {
        visited[j][i] = true;
        m[make_pair(j, i)] = 1;
        bfs(j, i, make_pair(j, i));
      }
    }
  }
  // calculate
  vector<int> vec;
  for (auto it : m) {
    vec.push_back(it.second);
  }
  sort(vec.begin(), vec.end());
  // output
  cout << vec.size() << "\n";
  for (auto it : vec) {
    cout << it << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n;
  numbering();
}

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, -1, 0, 1};

int r, c;
int hr, hc;            // initial place
char arr[1002][1002];  // adj same alphabet is same region
char visited[1002][1002];

string tracks;  // U, D, L, R, W(place ward in current point)

vector<pii> wards;



void print() {
  for (int j = 1; j <= r; j++) {
    for (int i = 1; i <= c; i++) {
      cout << (visited[j][i] ? '.' : '#');
    }
    cout << "\n";
  }
}

pii inverse_tracks() {
  int y = hr;
  int x = hc;
  for (char c : tracks) {
    // U, D, L, R, W
    if (c == 'W') {
      wards.push_back({y, x});
    } else if (c == 'U') {
      y -= 1;
    } else if (c == 'D') {
      y += 1;
    } else if (c == 'L') {
      x -= 1;
    } else if (c == 'R') {
      x += 1;
    }
  }

  sort(wards.begin(), wards.end());
  wards.erase(unique(wards.begin(), wards.end()), wards.end());

  return {y, x};
}

void bfs(int y, int x) {
  const char color = arr[y][x];
  queue<pii> q;
  q.push({y, x});
  visited[y][x] = true;

  while (!q.empty()) {
    pii p = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = p.first + dy[i];
      int nx = p.second + dx[i];
      if (visited[ny][nx]) continue;
      if (color == arr[ny][nx]) {
        q.push({ny, nx});
        visited[ny][nx] = true;
      }
    }
  }
}

// ward lights up all points in same region
void solve() {
  pii last_point = inverse_tracks();
  for (pii p : wards) {
    int y = p.first;
    int x = p.second;
    if (visited[y][x]) continue;
    bfs(y, x);
  }

  visited[last_point.first][last_point.second] = true;
  for (int i = 0; i < 4; i++) {
    int ny = last_point.first + dy[i];
    int nx = last_point.second + dx[i];
    visited[ny][nx] = true;
  }

  print();
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> r >> c;

  string input;
  for (int j = 1; j <= r; j++) {
    cin >> input;
    for (int i = 1; i <= c; i++) {
      arr[j][i] = input[i - 1];
    }
  }
  cin >> hr >> hc;
  cin >> tracks;

  solve();
}

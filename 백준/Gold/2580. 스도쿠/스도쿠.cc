#include <bits/stdc++.h>
using namespace std;
#define y first
#define x second
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

int arr[9][9];
priority_queue<pipii, vector<pipii>, greater<pipii> > pq;

void print() {
  for (int j = 0; j < 9; j++) {
    for (int i = 0; i < 9; i++) {
      cout << arr[j][i] << " ";
    }
    cout << "\n";
  }
}

vector<int> recommend(pii p) {
  vector<int> ret;
  int visited[10] = {};
  for (int k = 0; k < 9; k++) {
    visited[arr[p.y][k]] = true;
    visited[arr[k][p.x]] = true;
  }
  int y_start = p.y - p.y % 3;
  int x_start = p.x - p.x % 3;
  for (int j = y_start; j < y_start + 3; j++) {
    for (int i = x_start; i < x_start + 3; i++) {
      visited[arr[j][i]] = true;
    }
  }
  for (int i = 1; i <= 9; i++) {
    if (!visited[i]) ret.push_back(i);
  }
  return ret;
}

bool setNumber() {
  if (pq.empty()) {
    print();
    return true;
  }
  pii p = pq.top().second;
  pq.pop();
  vector<int> vec = recommend(p);
  for (int it : vec) {
    arr[p.y][p.x] = it;
    if (setNumber()) return true;
  }
  arr[p.y][p.x] = 0;  // reset
  pq.push({vec.size(), p});
  return false;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  for (int j = 0; j < 9; j++) {
    for (int i = 0; i < 9; i++) {
      cin >> arr[j][i];
      if (arr[j][i] == 0) pq.push({9, {j, i}});
    }
  }
  setNumber();
}

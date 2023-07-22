#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> vec(48);
vector<int> P(48);
vector<int> S(48);

bool check() {
  int temp[48];
  for (int i = 0; i < n; i++) {
    temp[vec[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    if (temp[i] % 3 != P[i]) {
      return false;
    }
  }
  return true;
}

void shuffle() {
  vector<int> temp(48);
  for (int i = 0; i < n; i++) {
    temp[S[i]] = vec[i];
  }
  vec = temp;
}
void solve() {
  for (int i = 0; i < 200000; i++) {
    if (check()) {
      cout << i << "\n";
      return;
    }
    shuffle();
  }
  cout << "-1\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> P[i];
    vec[i] = i;
  }
  for (int i = 0; i < n; i++) {
    cin >> S[i];
  }

  solve();
}

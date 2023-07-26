#include <bits/stdc++.h>
using namespace std;

int T;
int n, m;

int happy[10001];
bool visited[10001] = {};
bool getHappy(int val) {
  if (visited[val] && happy[val] < 0) {
    happy[val] = 0;
  } else if (!visited[val]) {
    visited[val] = true;
    vector<int> seq;
    int v = val;
    while (v > 0) {
      seq.push_back(v % 10);
      v /= 10;
    }
    int sum = 0;
    for (int it : seq) {
      sum += it * it;
    }
    happy[val] = getHappy(sum);
  }
  return happy[val];
}

int prime[10001] = {};
void getPrime() {
  prime[2] = 2;
  for (int i = 3; i <= 10000; i += 2) {
    prime[i] = i;
  }
  for (int i = 3; i <= 10000; i += 2) {
    for (int j = i * i; j <= 10000; j += i) {
      prime[j] = 0;
    }
  }
}

void solve() {
  cin >> n >> m;
  cout << n << " " << m << " ";
  cout << (happy[m] && prime[m] > 0 ? "YES\n" : "NO\n");
}

void init() {
  getPrime();
  fill_n(happy, 10001, -1);  // unset
  happy[1] = 1;
  for (int i = 1; i <= 10000; i++) {
    getHappy(i);
  }
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */
  cin >> T;
  init();
  while (T--) {
    solve();
  }
}

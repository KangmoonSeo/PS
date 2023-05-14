#include <bits/stdc++.h>
#define min(a, b) a > b ? b : a
using namespace std;
int n;
int _next[100001];

void oil() {
  int mem = 1e9;
  unsigned long long answer = 0;

  for (int i = 0; i < n - 1; i++) {
    cin >> _next[i];
  }
  int input;
  for (int i = 0; i < n; i++) {
    cin >> input;
    mem = min(mem, input);
    answer += mem * _next[i];
  }
  cout << answer << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n;
  oil();
}

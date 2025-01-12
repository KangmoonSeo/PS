#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

vector<int> numbers;
vector<char> ops;

ll calc(ll n1, ll n2, char op) {
  if (op == '+')
    return n1 + n2;
  else if (op == '-')
    return n1 - n2;
  else
    return n1 * n2;
}

ll task(vector<int> const picker) {
  bool visited[10] = {};
  for (int pick : picker) {
    visited[pick] = true;
  }
  ll n1 = numbers[0];
  int i;
  for (i = 0; i < ops.size(); i++) {
    ll n2 = numbers[i + 1];
    if (visited[i + 1]) {
      ll n3 = numbers[i + 2];
      n2 = calc(n2, n3, ops[i + 1]);
      n1 = calc(n1, n2, ops[i]);
      i++;
    } else {
      n1 = calc(n1, n2, ops[i]);
    }
  }

  return n1;
}

vector<vector<int>> picker_list;
vector<int> bt;

void BT(int init = 0) {
  if (init >= ops.size()) {
    picker_list.push_back(bt);
    return;
  }
  for (int i = init; i < ops.size(); i++) {
    bt.push_back(i);
    BT(i + 2);
    bt.pop_back();
  }
  picker_list.push_back(bt);
}

ll solve() {
  BT();
  ll ans = -(1 << 31);
  for (vector<int> picker : picker_list) {
    ll ret = task(picker);
    ans = max(ans, ret);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n;

  string input;
  cin >> input;

  for (int i = 0; i < n; i += 2) {
    int val = input[i] - '0';
    numbers.push_back(val);
    if (i < n - 1) ops.push_back(input[i + 1]);
  }

  ll ans = solve();
  cout << ans << "\n";
}

#include <bits/stdc++.h>
#define max(a, b) a > b ? a : b
using namespace std;

vector<int> add(vector<int> n1, vector<int> n2) {
  reverse(n1.begin(), n1.end());
  reverse(n2.begin(), n2.end());
  int l1 = n1.size();
  int l2 = n2.size();
  int length = max(l1, l2);
  vector<int> ret(length + 1);
  for (int i = 0; i < length; i++) {
    int tmp = 0;
    if (i < l1) tmp += n1[i];
    if (i < l2) tmp += n2[i];
    ret[i] += tmp % 10;
    ret[i + 1] += tmp / 10;
  }
  if (ret[length] == 0) ret.pop_back();
  reverse(ret.begin(), ret.end());
  return ret;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  int n;  // input
  string s1, s2;
  cin >> s1 >> s2;

  vector<int> v1(s1.size());
  for (int i = 0; i < s1.size(); i++) {
    v1[i] = s1[i] - '0';
  }

  vector<int> v2(s2.size());
  for (int i = 0; i < s2.size(); i++) {
    v2[i] = s2[i] - '0';
  }

  vector<int> ans = add(v1, v2);
  int l = ans.size();
  for (int i = 0; i < l; i++) {
    cout << ans[i];
  }

  cout << "\n";
}

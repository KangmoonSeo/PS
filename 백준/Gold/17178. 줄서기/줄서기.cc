#include <bits/stdc++.h>
using namespace std;

int n, cur = 0;
vector<vector<string> > vec;
vector<string> ans;
vector<string> seq;

bool cmp(string a, string b) {
  string as = a.substr(0, 1);
  string bs = b.substr(0, 1);
  if (as != bs) return as < bs;
  int ai = stoi(a.substr(2));
  int bi = stoi(b.substr(2));
  return ai < bi;
}

void pop_seq() {
  int len = seq.size();
  while (len--) {
    string str = seq.back();
    if (ans[cur] == str) {
      cur++;
      seq.pop_back();
    } else {
      return;
    }
  }
}
void solve() {
  sort(ans.begin(), ans.end(), cmp);

  for (vector<string> v : vec) {
    for (string str : v) {
      if (ans[cur] != str) {
        seq.push_back(str);
      } else {
        cur++;
        pop_seq();
      }
    }
  }
  cout << (seq.empty() ? "GOOD\n" : "BAD\n");
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n;
  string str;
  for (int i = 0; i < n; i++) {
    vector<string> tmp;
    for (int i = 0; i < 5; i++) {
      cin >> str;
      tmp.push_back(str);
      ans.push_back(str);
    }
    vec.push_back(tmp);
  }

  solve();
}

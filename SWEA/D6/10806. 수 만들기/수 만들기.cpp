#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, k;
int arr[11];

int solve() {
  // 목표: X = 0 -> k 만들기
  // 단, X += D 최소화해서
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  cin >> k;

  priority_queue<pii, vector<pii>, greater<pii>> pq;  // {hop, k}
  pq.push({0, k});

  while (pq.top().second > 0) {
    auto p = pq.top();
    pq.pop();

    int hop = p.first;
    int x = p.second;

    pq.push({hop + x, 0});

    for (int i = 0; i < n; i++) {
      pq.push({hop + x % arr[i], x / arr[i]});
    }
  }
  return pq.top().first;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */
  //  freopen("sample_input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int test_case = 1; test_case <= T; test_case++) {
    auto ret = solve();
    cout << "#" << test_case << " " << ret << "\n";
  }
}

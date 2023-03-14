#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  int arr[100005];

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    arr[i] += arr[i - 1];  // Sliding window algorithm
  }

  int a, b;

  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    cout << arr[b] - arr[a - 1] << "\n";
  }
}
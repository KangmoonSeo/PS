#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> v_l;

v_l arr(6, vector<int>(6));
int n;  // input;
long long b;

void print(v_l arr) {
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= n; i++) {
      cout << arr[j][i]%1000 << " ";
    }
    cout << "\n";
  }
}
v_l cross(v_l a, v_l b) {
  v_l ret(6, vector<int>(6));
  for (int y = 1; y <= n; y++) {
    for (int x = 1; x <= n; x++) {
      for (int w = 1; w <= n; w++) {
        ret[y][x] += a[w][x] * b[y][w];
        ret[y][x] %= 1000;
      }
    }
  }
  return ret;
}

v_l calc(v_l mat, long long n) {
  if (n == 1) return mat;
  v_l tmp = calc(mat, n / 2);
  v_l ret = cross(tmp, tmp);
  if (n % 2 == 1) {
    ret = cross(arr, ret);
  }
  return ret;
}

void matrix() {
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= n; i++) {
      cin >> arr[j][i];
    }
  }
  print(calc(arr, b));
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n >> b;
  matrix();
}

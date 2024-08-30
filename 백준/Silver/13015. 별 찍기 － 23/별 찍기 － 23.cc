#include <bits/stdc++.h>
using namespace std;

int n;

void print_cap() {
  string buf = "";

  for (int i = 0; i < n; i++) {
    buf += "*";
  }
  for (int i = 0; i < n * 2 - 3; i++) {
    buf += " ";
  }
  for (int i = 0; i < n; i++) {
    buf += "*";
  }

  buf += "\n";
  cout << buf;
}
void print_barrel() {
  string buf = "";
  buf += "*";
  for (int i = 0; i < n - 2; i++) {
    buf += " ";
  }
  buf += "*";
  cout << buf;
}
void print_middle() {
  string buf = "";
  for (int i = 0; i < n - 1; i++) {
    buf += " ";
  }
  buf += "*";
  for (int i = 0; i < n - 2; i++) {
    buf += " ";
  }
  buf += "*";
  for (int i = 0; i < n - 2; i++) {
    buf += " ";
  }

  buf += "*\n";
  cout << buf;
}

void solve() {
  // function works here
  //
  print_cap();
  for (int j = 0; j < n - 2; j++) {
    for (int i = 0; i < j + 1; i++) {
      cout << " ";
    }
    print_barrel();
    for (int i = 0; i < n * 2 - 5 - 2 * j; i++) {
      cout << " ";
    }
    print_barrel();
    cout << "\n";
  }
  print_middle();

  for (int j = 0; j < n - 2; j++) {
    for (int i = n - j - 3; i >= 0; i--) {
      cout << " ";
    }
    print_barrel();
    for (int i = 0; i < j * 2 + 1; i++) {
      cout << " ";
    }
    print_barrel();
    cout << "\n";
  }
  print_cap();
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n;
  solve();
}

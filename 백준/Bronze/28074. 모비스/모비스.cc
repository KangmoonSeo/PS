#include <bits/stdc++.h>
using namespace std;

string input;
void solve() {
  const string STR = "MOBIS";

  bool isOK = false;
  for (int i = 0; i < 5; i++) {
    int length = input.size();
    for (int j = 0; j < length; j++) {
      if (STR[i] == input[j]) {
        isOK = true;
      }
    }
    if (!isOK) {
      cout << "NO\n";
      return;
    }

    isOK = false;
    if (i == 4) {
      cout << "YES\n";
      return;
    }
  }
}
int main() {
  cin >> input;
  solve();
}
#include <bits/stdc++.h>
#define max(a, b) a > b ? a : b
#define min(a, b) a > b ? b : a
using namespace std;
int n;

void funk() {
  string input;
  cin >> input;
  char T = input.back();
  bool isTrue = false;
  string charset = "yuiopOPhjklbnm";
  int length = charset.size();
  for (int i = 0; i < length; i++) {
    if (charset[i] == T) {
      isTrue = true;
      break;
    }
  }
  if (isTrue) cout << "0\n";
  else cout << "1\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  cin >> n;
  funk();
}

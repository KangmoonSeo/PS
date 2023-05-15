#include <bits/stdc++.h>
#define max(a, b) a > b ? a : b
#define min(a, b) a > b ? b : a
using namespace std;
int n;
map<string, double> score;
void calc() {
  score["A+"] = 4.5;
  score["A0"] = 4.0;
  score["B+"] = 3.5;
  score["B0"] = 3.0;
  score["C+"] = 2.5;
  score["C0"] = 2.0;
  score["D+"] = 1.5;
  score["D0"] = 1.0;
  score["F"] = 0.0;

  string s1, s3;
  double sum = 0;
  double myScore = 0;
  double i2;
  int T = 20;
  while (T--) {
    cin >> s1 >> i2 >> s3;
    if (s3 == "P") continue;
    sum += i2;
    myScore += i2 * score[s3];
  }
  double ans = myScore / sum;
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  calc();
}

#include <bits/stdc++.h>
using namespace std;

string str = "INITIAL";
vector<int> e(256);

void encoder() {
  string s[4];
  s[0] = "=-0987654321`";
  s[1] = "\\][POIUYTREWQ";
  s[2] = "';LKJHGFDSA";
  s[3] = "/.,MNBVCXZ";
  for (int i = 0; i < 4; i++) {
    string target = s[i];
    for (int j = 1; j < target.size(); j++) {
      cout << "e['" << target[j - 1] << "'] = '" << target[j] << "';\n";
    }
    cout << "\n";
  }
}
void solve() {
  e[' '] = ' ';
  e['='] = '-';
  e['-'] = '0';
  e['0'] = '9';
  e['9'] = '8';
  e['8'] = '7';
  e['7'] = '6';
  e['6'] = '5';
  e['5'] = '4';
  e['4'] = '3';
  e['3'] = '2';
  e['2'] = '1';
  e['1'] = '`';

  e['\\'] = ']';
  e[']'] = '[';
  e['['] = 'P';
  e['P'] = 'O';
  e['O'] = 'I';
  e['I'] = 'U';
  e['U'] = 'Y';
  e['Y'] = 'T';
  e['T'] = 'R';
  e['R'] = 'E';
  e['E'] = 'W';
  e['W'] = 'Q';

  e['\''] = ';';
  e[';'] = 'L';
  e['L'] = 'K';
  e['K'] = 'J';
  e['J'] = 'H';
  e['H'] = 'G';
  e['G'] = 'F';
  e['F'] = 'D';
  e['D'] = 'S';
  e['S'] = 'A';

  e['/'] = '.';
  e['.'] = ',';
  e[','] = 'M';
  e['M'] = 'N';
  e['N'] = 'B';
  e['B'] = 'V';
  e['V'] = 'C';
  e['C'] = 'X';
  e['X'] = 'Z';
  int length = str.size();
  string ans = "";
  for (int i = 0; i < length; i++) {
    ans += e[str[i]];
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization
  while (str != "") {
    getline(cin, str);
    solve();
  }
}

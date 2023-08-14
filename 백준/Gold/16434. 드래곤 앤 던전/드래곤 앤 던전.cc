#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, atk, curatk, maxhp, curhp;
int arr[123457][3];

bool monster(int a, int h) {
  ll cycle = (h + curatk - 1) / curatk;
  curhp -= a * (cycle - 1);
  return (curhp > 0);
}

void potion(int a, int h) {
  curatk += a;
  curhp += h;
  curhp = min(curhp, maxhp);
}

bool simulate() {
  curhp = maxhp;
  curatk = atk;
  for (int i = 1; i <= n; i++) {
    if (arr[i][0] == 1) {
      if (!monster(arr[i][1], arr[i][2])) return false;
    } else {
      potion(arr[i][1], arr[i][2]);
    }
  }
  return true;
}
void solve() {
  maxhp = 1024;
  ll gap = 1024;
  ll ceil_hp = -1;
  while (true) {
    bool fl = simulate();
    if (fl) {
      ceil_hp = maxhp;
      maxhp -= gap;
      gap /= 2;
      if (gap == 0) break;
    } else {
      maxhp += gap;
      if (ceil_hp < 0) gap *= 2;
    }
  }
  cout << maxhp + 1 << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n >> atk;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
  }
  solve();
}

#include <bits/stdc++.h>
#define init first
#define fin second
using namespace std;
typedef pair<int, int> pii;

vector<pii> room;
priority_queue<int, vector<int>, greater<int> > pq;

void greedy(int n) {
  int length = room.size();
  for (int i = 0; i < length; i++) {
    pii p = room[i];
    pq.push(p.fin);
    if (pq.top() <= p.init) {
      pq.pop();
    }
  }
  cout << pq.size() << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  // optimization

  int n;  // input
  cin >> n;
  int i1, i2;
  while (n--) {
    cin >> i1 >> i2;
    room.push_back(make_pair(i1, i2));
  }
  sort(room.begin(), room.end());
  greedy(n);
}

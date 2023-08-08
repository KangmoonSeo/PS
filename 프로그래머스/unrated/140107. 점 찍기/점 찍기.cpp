#include <string>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;
long long solution(int k, int d) {
  ll answer = 0;
  ll lim = (ll)pow(d, 2);

  for (int i = 0; i <= d; i += k) {
    answer++;
    ll pj = lim - (ll)pow(i, 2);
    ll j = floor(sqrt(pj));
    answer += (j / k);
  }
  return answer;
}
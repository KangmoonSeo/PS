#include <vector>
#include <unordered_map>

using namespace std;
unordered_map<int, int> m;

int solution(vector<int> nums)
{
  int answer = 0;

  for (int it : nums) {
    if (m[it] <= 0) m[it] = 0;
    m[it] += 1;
  }

  answer = min(m.size(), nums.size() / 2);

  return answer;
}
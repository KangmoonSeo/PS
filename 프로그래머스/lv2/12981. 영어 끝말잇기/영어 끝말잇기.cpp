#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
  vector<int> answer;
  unordered_map<string, int> um;
  string mem;
  int cnt = 1;
  for (string it : words) {
    if (cnt <= 1) {
      um[it]++;
      mem = it;
      cnt++;
      continue;
    }
    if (mem.back() != it[0] || um[it] > 0) break;
    um[it]++;
    mem = it;
    cnt++;
  }
  
  int per = (cnt - 1) % n + 1;
  int turn = (cnt - 1) / n + 1;
  if (cnt > words.size()) per = 0, turn = 0;

  answer.push_back(per);
  answer.push_back(turn);
  return answer;
}

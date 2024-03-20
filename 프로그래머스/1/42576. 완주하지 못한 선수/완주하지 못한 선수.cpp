#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> m;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    for (auto p : participant) {
        if (m[p] <= 0) m[p] = 0;
        m[p] += 1;
    }
    for (auto p : completion) {
        m[p] -= 1;
    }
    for (auto p : participant) {
        if (m[p] > 0) answer = p;

    }
        
    return answer;
}
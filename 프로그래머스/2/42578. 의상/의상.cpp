#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> m;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    
    for (auto cloth : clothes) {
        if (m[cloth[1]] <= 0) m[cloth[1]] = 0;
        m[cloth[1]] += 1;
    }
    
    for (auto it : m) {
        answer *= (it.second + 1);
    }
    answer -= 1;
    
    
    return answer;
}
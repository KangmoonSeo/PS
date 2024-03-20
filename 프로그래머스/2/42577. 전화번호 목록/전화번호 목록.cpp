#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> m;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    
    for (string phone : phone_book) {
        if (m[phone]<= 0) m[phone] = 1;  
    }
    
    for (string phone : phone_book) { 
        
        string pat = "";
        
        for (char c : phone) {
            pat += c;
            if (pat == phone) continue;
            if (m[pat] > 0) return false;
        }    
    }
    
    return true;
    return answer;
}
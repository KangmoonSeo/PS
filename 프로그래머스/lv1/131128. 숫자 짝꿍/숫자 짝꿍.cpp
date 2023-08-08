#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string solution(string X, string Y) {
    int cnt[2][10] = {};
    for (char it : X) {
        cnt[0][it - '0']++;
    }
    for (char it : Y) {
        cnt[1][it - '0']++;
    }
    
    string answer = "";
    
    for (int i = 9; i >= 0; i--) {
        int len = min(cnt[0][i], cnt[1][i]);
        if (i == 0 && answer.empty()) {
            if (len > 0) return "0";
            else return "-1";
        }
        while (len--) {
            answer += (i + '0');
        }
    }
    return answer;
}
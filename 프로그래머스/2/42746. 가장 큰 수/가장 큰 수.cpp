#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
    return a + b > b + a; 
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> vec;
    
    for (int i : numbers) {
        vec.push_back(to_string(i));
    }
    
    sort(vec.begin(), vec.end(), cmp);
    for (string s : vec) {
        answer += s;
    }
    if (answer[0] == '0') return "0"; 

    return answer;
}
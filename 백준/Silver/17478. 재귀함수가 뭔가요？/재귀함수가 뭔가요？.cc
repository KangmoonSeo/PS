#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

const string under = "____";
const string eoneu =
    "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
const string question = "\"재귀함수가 뭔가요?\"\n";
const string jal[3] = {
    "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 "
    "있었어.\n",
    "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 "
    "주었지.\n",
    "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 "
    "찾아와서 물었어.\"\n"};
const string jaegui = "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
const string rago = "라고 답변하였지.\n";

void recur(int n, int k) {
  string prefix = "";
  for (int i = 0; i < k; i++) prefix += under;

  cout << prefix << question;
  if (n == 0) {  // 명답
    cout << prefix << jaegui;
  } else {  // 변명
    for (int j = 0; j < 3; j++) {
      cout << prefix << jal[j];
    }
    recur(n - 1, k + 1);
  }
  cout << prefix << rago;
}
void q(int n) {
  cout << eoneu;
  recur(n, 0);
}
int main() {
  // 실행속도 최적화 start
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // 실행속도 최적화 end

  int n;  // input
  cin >> n;
  q(n);
}

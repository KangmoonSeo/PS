#include <bits/stdc++.h>
using namespace std;

int n;

/**
 * @returns 등록한 단어가 '일관성' 있는지 여부
 */
struct Node {
  Node* children[10];
  bool isEnd = false;
};

bool register_number(Node* root, string s) {
  bool ret = true;
  Node* current = root;

  // i in [0, s.size - 1)
  for (int i = 0; i < s.size() - 1; i++) {
    int idx = s[i] - '0';
    if (current->children[idx] == nullptr) {
      current->children[idx] = new Node();
    }
    current = current->children[idx];
    if (current->isEnd) ret = false;
  }
  // i  == s.size - 1; 새로 만드는 게 아니라면 내가 누군가의 일관성을 해치는 것.
  int idx = s[s.size() - 1] - '0';
  if (current->children[idx] == nullptr) {
    current->children[idx] = new Node();
  } else {
    ret = false;
  }
  current = current->children[idx];
  current->isEnd = true;
  return ret;
}

/**
 *
 * @brief "일관성"
 *
 *
 * @returns
 * '일관성'이 있는가? -> "YES" or "NO"
 */
string solve() {
  Node* root = new Node();

  string input;
  bool is_consistant = true;
  for (int i = 0; i < n; i++) {
    cin >> input;
    is_consistant &= register_number(root, input);
  }

  if (is_consistant) {
    // '일관성'이 있는 단어집
    return "YES";
  } else {
    return "NO";
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */
  int test_case;

  cin >> test_case;

  for (int i = 1; i <= test_case; i++) {
    cin >> n;
    auto ans = solve();
    cout << ans << "\n";
  }
}

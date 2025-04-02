#include <bits/stdc++.h>
using namespace std;

int n;

struct Node {
  Node* children['z' - 'a' + 1];
  int children_size = 0;
  bool isEnd = false;
};

void register_word(Node* root, string s) {
  Node* current_node = root;
  for (auto c : s) {
    int idx = c - 'a';
    if (current_node->children[idx] == nullptr) {
      current_node->children[idx] = new Node();
      current_node->children_size += 1;
    }
    current_node = current_node->children[idx];
  }
  current_node->isEnd = true;
}

int validate_word(Node* root, string word) {
  //
  int cnt = 0;

  Node* current_node = root;
  // i=0; initially typed
  current_node = current_node->children[word[0] - 'a'];
  cnt += 1;
  // i>0
  for (int i = 1; i < word.size(); i++) {
    int idx = word[i] - 'a';
    // 2. try autocomplete
    if (current_node->children_size == 1 && !current_node->isEnd) {
      // autocompeleted
      current_node = current_node->children[idx];
    } else {
      // manually iterated
      current_node = current_node->children[idx];
      cnt += 1;
    }
  }
  return cnt;
}

void delete_trie(Node* node) {
  if (node == nullptr) return;
  for (int i = 0; i < ('z' - 'a' + 1); i++) {
    delete_trie(node->children[i]);  // 자식 노드 재귀적으로 삭제
  }
  delete node;  // 부모 노드 삭제
}
double solve() {
  Node* root = new Node();
  vector<string> words;

  string input;
  for (int i = 0; i < n; i++) {
    cin >> input;
    words.push_back(input);
    register_word(root, input);
  }

  int cnt = 0;
  for (auto word : words) {
    cnt += validate_word(root, word);
  }
  delete_trie(root);
  double ans = (double)cnt / words.size();
  return ans;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  while (cin >> n) {
    double ans = solve();
    cout << fixed << setprecision(2) << ans << "\n";
  }
}

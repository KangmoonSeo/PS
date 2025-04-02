#include <bits/stdc++.h>
using namespace std;

int n;

struct Node {
  unordered_map<char, Node*> children;
  bool isEnd = false;
};

void register_word(Node* root, string s) {
  Node* current_node = root;
  for (auto c : s) {
    if (current_node->children.find(c) == current_node->children.end()) {
      current_node->children[c] = new Node();
    }
    current_node = current_node->children[c];
  }
  current_node->isEnd = true;
}

int validate_word(Node* root, string word) {
  //
  int cnt = 0;

  Node* current_node = root;
  // i=0; initially typed
  current_node = current_node->children[word[0]];
  cnt += 1;
  // i>0
  for (int i = 1; i < word.size(); i++) {
    char c = word[i];
    // 2. try autocomplete
    if (current_node->children.size() == 1 && !current_node->isEnd) {
      // autocompeleted
      current_node = current_node->children[c];
    } else {
      // manually iterated
      current_node = current_node->children[c];
      cnt += 1;
    }
  }
  return cnt;
}

double solve() {
  // function works here
  //
  Node* root = new Node();
  string input;
  vector<string> words;

  for (int i = 0; i < n; i++) {
    cin >> input;
    words.push_back(input);
    register_word(root, input);
  }

  int cnt = 0;
  for (auto word : words) {
    cnt += validate_word(root, word);
  }
  double ans = (double)cnt / words.size();
  return ans;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  while (cin >> n) {
    auto ans = solve();
    cout << fixed << setprecision(2) << ans << "\n";
  }
}

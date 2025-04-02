#include <bits/stdc++.h>
using namespace std;
int n;

struct Node {
  Node* children['z' - 'a' + 1];
  int children_size = 0;
  bool isEnd = false;
};

const int MAX_NODES = 400001;
Node node_pool[MAX_NODES];
int node_cnt = 0;

Node* get_node() {
  Node* new_node = &node_pool[node_cnt++];

  // new Node()
  for (int i = 0; i < ('z' - 'a' + 1); i++) {
    new_node->children[i] = nullptr;
  }
  new_node->children_size = 0;
  new_node->isEnd = false;

  return new_node;
}

void register_word(Node* root, string s) {
  Node* current_node = root;
  for (auto c : s) {
    int idx = c - 'a';
    if (current_node->children[idx] == nullptr) {
      current_node->children[idx] = get_node();
      current_node->children_size += 1;
    }
    current_node = current_node->children[idx];
  }
  current_node->isEnd = true;
}

int validate_word(Node* root, string word) {
  int cnt = 0;
  Node* current_node = root;

  // i=0; initially typed
  current_node = current_node->children[word[0] - 'a'];
  cnt += 1;

  // i>0
  for (int i = 1; i < word.size(); i++) {
    int idx = word[i] - 'a';
    // try autocomplete
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

double solve() {
  // 노드 카운터 초기화
  node_cnt = 0;

  Node* root = get_node();
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
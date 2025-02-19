#include <iostream>
#include <string>
using namespace std;

class TrieNode {
 public:
  TrieNode* children[26];  // 알파벳 소문자만 처리
  bool isEnd;

  TrieNode() : isEnd(false) {
    for (int i = 0; i < 26; i++) children[i] = nullptr;
  }

  ~TrieNode() {
    for (int i = 0; i < 26; i++) delete children[i];
  }
};

class Trie {
 private:
  TrieNode* root;
  int count;      // k번째를 찾기 위한 카운터
  string result;  // 결과 문자열

  void findKthSuffixUtil(TrieNode* node, string& curr, int k) {
    if (result != "") return;  // 이미 찾았으면 종료

    if (node->isEnd) {
      if (count == k) {
        result = curr;
        return;
      }
      count++;
    }

    for (int i = 0; i < 26; i++) {
      if (node->children[i]) {
        curr.push_back('a' + i);
        findKthSuffixUtil(node->children[i], curr, k);
        curr.pop_back();
      }
    }
  }

 public:
  Trie() : root(new TrieNode()), count(0) {}
  ~Trie() { delete root; }

  void insert(const string& str) {
    TrieNode* current = root;
    for (char c : str) {
      int idx = c - 'a';
      if (!current->children[idx]) {
        current->children[idx] = new TrieNode();
      }
      current = current->children[idx];
    }
    current->isEnd = true;
  }

  string findKthSuffix(int k) {
    count = 0;
    result = "";
    string current = "";
    findKthSuffixUtil(root, current, k);
    return result == "" ? "none" : result;
  }
};

string solve() {
  int num;
  string target;
  cin >> num >> target;

  num -= 1;  // 1-based to 0-based

  Trie trie;
  for (int i = 0; i < target.length(); i++) {
    trie.insert(target.substr(i));
  }

  return trie.findKthSuffix(num);
}

int main() {
  int T;
  cin >> T;

  for (int test_case = 1; test_case <= T; test_case++) {
    cout << "#" << test_case << " " << solve() << "\n";
  }
  return 0;
}
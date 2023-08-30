#include <bits/stdc++.h>
using namespace std;

int n, k;

class Node {
 public:
  Node* parent;
  string val;
  vector<Node*> childs;

  Node(Node* p, string v, vector<Node*> c) {
    parent = p;
    val = v;
    childs = c;
  }
};
Node* root;

bool cmp(Node* a, Node* b) { return (a->val < b->val); }

void print(Node* node, string s) {
  if (node != root) {
    cout << s << node->val << "\n";
    s += "--";
  }
  auto vec = node->childs;
  sort(vec.begin(), vec.end(), cmp);
  for (auto it : vec) {
    print(it, s);
  }
}

void insert(Node* node, int TTL, int k) {
  if (TTL == k) return;
  string str;
  cin >> str;
  Node* nxt = nullptr;
  for (Node* x : node->childs) {
    if (x->val == str) {
      nxt = x;
    }
  }
  if (nxt == nullptr) {
    nxt = new Node(node, str, vector<Node*>());
    node->childs.push_back(nxt);
  }
  insert(nxt, TTL + 1, k);
}

void solve() {
  root = new Node(nullptr, "", vector<Node*>());

  string str;
  for (int i = 0; i < n; i++) {
    cin >> k;
    insert(root, 0, k);
  }
  print(root, "");
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */

  cin >> n;
  solve();
}

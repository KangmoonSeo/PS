#include <iostream>
#include <vector>

using namespace std;

int n;  // n in [1, 100000]
vector<int> max_heap;

/**
 * NOTE: 부모가 k인 경우, 자식은 2k, 2k+1에 존재
 */

void add_node(int val) {
  max_heap.push_back(val);
  int child_idx = max_heap.size() - 1;
  int parent_idx = child_idx / 2;

  while (parent_idx >= 1 && max_heap[child_idx] > max_heap[parent_idx]) {
    swap(max_heap[child_idx], max_heap[parent_idx]);
    child_idx = parent_idx;
    parent_idx = child_idx / 2;
  }
}

int delete_root_node() {
  if (max_heap.size() <= 1) return -1;  // 힙이 비어있으면 -1 반환

  int root_node_value = max_heap[1];
  max_heap[1] = max_heap.back();
  max_heap.pop_back();

  int parent_idx = 1;
  while (true) {
    int l_idx = parent_idx * 2;
    int r_idx = parent_idx * 2 + 1;
    int largest = parent_idx;

    if (l_idx < max_heap.size() && max_heap[l_idx] > max_heap[largest]) {
      largest = l_idx;
    }
    if (r_idx < max_heap.size() && max_heap[r_idx] > max_heap[largest]) {
      largest = r_idx;
    }

    if (largest == parent_idx) break;

    swap(max_heap[parent_idx], max_heap[largest]);
    parent_idx = largest;
  }

  return root_node_value;
}

void solve() {
  max_heap.clear();
  max_heap.push_back(-1);  // 1-based index 유지
  cin >> n;

  for (int i = 0; i < n; i++) {
    int cmd, val;
    cin >> cmd;

    if (cmd == 1) {
      cin >> val;
      add_node(val);
    } else {
      int val = delete_root_node();
       cout << val << " ";
    }
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */
  int T;

  cin >> T;

  for (int test_case = 1; test_case <= T; ++test_case) {
    cout << "#" << test_case << " ";
    solve();
    cout << "\n";
  }

  return 0;
}

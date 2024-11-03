#include <bits/stdc++.h>
using namespace std;

int n;            // [1, 50]
int k;            // [0, 36]
int arr[55][36];  // [0] -> LSB
int sum[55];
int profits[55][36];

bool compare(int u, int v) {
  for (int i = 55 - 1; i >= 0; i--) {
    if (profits[i][u] == profits[i][v]) continue;
    return profits[i][u] > profits[i][v];
  }
  return u > v;
}

// 치환할 알파벳이 무엇일지 우선순위를 정합니다.
vector<int> rank_arr(int k) {
  // 알파벳 별 이득을 계산합니다.
  for (int i = 0; i < 36; i++) {
    if (i == 35) continue;  // z 제외
    int weight = 35 - i;
    for (int j = 0; j < 55; j++) {
      profits[j][i] += arr[j][i] * weight;
    }
  }
  // 이득을 carry 합니다.
  for (int i = 0; i < 36; i++) {
    if (i == 35) continue;  // z 제외
    for (int j = 0; j < 55; j++) {
      int carry = profits[j][i] / 36;
      profits[j + 1][i] += carry;
      profits[j][i] = profits[j][i] % 36;
    }
  }

  vector<int> number_set;
  for (int i = 0; i < 36; i++) {
    number_set.push_back(i);
  }

  // 정렬합니다. profits[val_target][u] vs  profits[val_target][v]
  sort(number_set.begin(), number_set.end(), compare);

  // 이제 weight가 큰 순서로 k개를 뽑습니다.
  vector<int> ret;
  for (int i = 0; i < k; i++) {
    ret.push_back(number_set[i]);
  }
  return ret;
}

// 알파벳을 Z에 합병합니다.
void merge(int target) {
  const int z_index = 35;
  if (target == 35) return;
  for (int i = 0; i < 55; i++) {
    arr[i][z_index] += arr[i][target];
    arr[i][target] = 0;
  }
}

// 캐리합니다.
void flush() {
  for (int i = 0; i < 55; i++) {
    int carry = sum[i] / 36;
    sum[i + 1] += carry;
    sum[i] = sum[i] % 36;
  }
}

void apply_sum() {
  for (int i = 0; i < 55; i++) {
    sum[i] = 0;
    for (int j = 0; j < 36; j++) {
      sum[i] += arr[i][j] * j;
    }
  }
}

// 눈에 익숙한 36진수로 변환해 보여줍니다.
string arr_to_string() {
  string ret;
  string buf;
  for (int i = 0; i < 55; i++) {
    char val;
    if (sum[i] < 10) {
      val = '0' + sum[i];
    } else {
      val = 'A' + sum[i] - 10;
    }
    buf = val + buf;
    if (val != '0') {
      ret = buf + ret;
      buf = "";
    }
  }
  if (ret == "") ret = "0";
  return ret;
}

void solve() {
  for (int j = 0; j < n; j++) {
    string input;  // [50] -> LSB
    cin >> input;
    int len = input.size();
    for (int i = 0; i < len; i++) {
      char c = input[len - 1 - i];  // [0] -> LSB
      int val;
      if (c < 'A') {
        val = c - '0';
      } else {
        val = c - 'A' + 10;
      }
      sum[i] += val;
      arr[i][val]++;  // i자리 수 val만큼 증가
    }
  }

  cin >> k;

  vector<int> number_set = rank_arr(k);
  for (int i : number_set) {
    merge(i);
  }

  apply_sum();
  flush();
  string ans = arr_to_string();
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */
  //  freopen("sample_input.txt", "r", stdin);

  cin >> n;
  solve();
}

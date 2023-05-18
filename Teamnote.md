# Teamnote for PS
- c++17 기준으로 작성했습니다. 
<!-- update: 23.05.18. -->
 
## 목차
0. [기본 함수](#기본-함수)
1. [누적합](#누적합) <!-- 2. [구현](#구현) -->
2. [DP](#dp)
3. [그래프 이론](#그래프-이론)
4. [그래프 탐색](#그래프-탐색)<!-- 5. [트리순회](#트리순회) -->
5. [최단거리](#최단거리) <!-- 6. [완전탐색](#완전탐색) -->
6. [백트래킹](#백트래킹)
7. [비트마스킹](#비트마스킹)
8. [그리디](#그리디) 
<!-- 10. [라인스위핑](#라인스위핑) --><!-- 11. [투포인터](#투포인터) --> <!-- 12. [LIS](#lis) --><!--9. [이분탐색](#이분탐색)--> <!-- 11. [펜윅트리](#펜윅트리) -->

## 기본 함수

- 형변환
```cpp
int val = stoi(str); // string to int
string val = to_string(i); // int to string
int val = c - '0'; // char to int
```

- 문자열
```cpp
str.substr(int pos=0, int length);
```
- 자료구조
```cpp
fill_n(T* first, int n, T elem); // 배열 또는 벡터를 elem으로 초기화
q = queue<T>(); // queue 초기화 (크기 0)

lower_bound(T* array, T* array + n, int target); // 배열
lower_bound(iter v.begin(), iter v.end(), int target); // 벡터

// priority_queue
struct cmp {
  bool operator()(T a, T b) { return a.elem > b.elem; } // 오름차순
};
priority_queue<T, vector<T>, cmp> pq;

// tuple
tuple<T1, T2, T3> tupleValue = make_tuple(v1, v2, v3);
cout << get<2>(tupleValue); // tupleValue v3 호출 
```
--- 
## 누적합

누적합 알고리즘은 sequence를 입력받는 시점에서 이전까지의 누적합에 현재 요소를 더하여 새로운 누적합을 계산한다. `// n * O(1)`

계산된 누적합은 결과를 저장하는 새로운 배열이나 리스트에 순차적으로 추가되며, 구간을 사용할 때 `arr[b] - arr[a - 1]` 로 꺼내 쓴다. `// O(1)`

수행 시간이 `O(1)` 이기 때문에, 누적 요소를 반복하여 사용하는 상황에서 유리하다. 

- x1부터 x2까지의 1차원 구간 합
```cpp
for (int i = 1; i <= n; i++) {
  cin >> pSum[i];
  pSum[i] += pSum[i - 1];  // 누적합, O(1)
}
cout << pSum[x2] - pSum[x1 - 1] << "\n"; // O(1)
```

- (x1, y1)부터 (x2, y2)까지의 2차원 구간 합
```cpp
for (int j = 1; j <= n; j++) {
  for (int i = 1; i <= n; i++) {
    cin >> pSum[i][j];
    pSum[i][j] += pSum[i - 1][j]; // 누적합, O(1)
   }
}
int ans = 0;  
cin >> y1 >> x1 >> y2 >> x2;
for (int j = y1; j <= y2; j++) {
  ans += pSum[x2][j] - pSum[x1 - 1][j]; // n * O(1)
} 
cout << ans << "\n";
```
--- 
## DP
큰 문제 DP[N]을 작은 하위 문제로 나눈 후 작은 문제를 먼저 해결하고, 이를 통해 중복 계산을 피하며 최적해를 찾는 설계 기법이다.

DP[0] > DP[1] > ... > DP[N] 순으로 최적해를 찾는다. 이때 DP[k] 최적해 계산에 DP[k-1] 최적해를 사용한다. 

bottom-up 방식이다.  

--- 
## 그래프 이론
- 정점: V = Vertex 또는 arc
- 간선: E = Edge 또는 node
- 가중치: W = Weight

### 그래프의 표현
1. Adjacency matrix
```cpp
int adj[100001][100001]; // 가중치가 없다면 bool
adj[v1][v2] = val;
```

2. Adjacency list
```cpp
vector<pair<int, int> > adj[100001];  // 가중치가 없다면 vector<int>
adj[v1].push_back(make_pair(v2, val));
```

--- 
## 그래프 탐색
> 깊이 우선 탐색(DFS), 너비 우선 탐색(BFS)
- 
```cpp
bool visited[100001] = {}; // false로 초기화
```
### DFS
: 그래프의 깊은 부분을 우선적으로 탐색하는 알고리즘
- 시작 정점에서 한 방향으로 최대한 깊게 이동하다가 더 이상 진행할 수 없을 때, 다른 분기로 돌아와 탐색을 진행함
- 스택이나 재귀 호출을 이용하여 구현할 수 있으며, 백트래킹과 함께 활용됨
```cpp
```
### BFS
: 그래프의 가까운 부분을 우선적으로 탐색하는 알고리즘
- 시작 정점에서 인접한 정점들을 모두 탐색한 후, 탐색되지 않은 정점을 큐에 넣고 순서대로 탐색함
- 큐를 이용하여 구현할 수 있으며, 최단 경로를 찾는 문제에 
```cpp
```
--- 
## 최단거리

### 플로이드-워셜
: 가중치 방향그래프에서, 모든 정점 쌍 사이의 최단 경로를 찾는 DP 기반의 알고리즘
> 시간복잡도: O(V^3)
- input: 가중치 방향그래프 W[n][n], 연결이 끊긴 간선은 INF로 초기화 되어있음
- output: i에서 j로 가는 최소 비용을 담은 배열 D[n][n]
- 활용: 도시 간의 최단 경로, 항공 노선 최적화 
```cpp
void floid() {
  vector<vector<int> > D = W; // 초기 값 D_0
  for (int k = 1; k <= n; k++) { // D_1, D_2, ... , D_n; D_k 계산에 D_k-1를 사용함
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (i == j) continue;
        D[i][j] = min(D[i][j], D[i][k] + D[k][j]);  
      }
    }
  }
}
 ```
 
### 프림
> 시간복잡도: O(V^2)
- input: 
- output: 
```cpp
 //
```

### 다익스트라
 > 시간복잡도: O(V^2)
 - input: 
 - output: 
 ```cpp
 //
 ```
--- 
## 백트래킹


--- 
## 비트마스킹
1 << 4 == 1000(2) == 16

비어있는 공집합 S가 주어졌을 때, 아래 연산을 수행하는 프로그램을 작성하시오.

add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
all: S를 {1, 2, ..., 20} 으로 바꾼다.
empty: S를 공집합으로 바꾼다. 
```cpp
void set(int n) {
  int BIT = 0;
  string command;
  int input;

  for (int i = 0; i < n; i++) {
    cin >> command;

    if (command == "all") {
      BIT = (1 << 21) - 1;
      continue;
    }
    if (command == "empty") {
      BIT = 0;
      continue;
    }
    if (command == "add") {
      cin >> input;
      BIT = BIT | (1 << input);
      continue;
    }
    if (command == "remove") {
      cin >> input;
      BIT = BIT & ~(1 << input);
      continue;
    }
    if (command == "check") {
      cin >> input;
      cout << ((BIT & (1 << input)) ? 1 : 0) << "\n";
      continue;
    }
    if (command == "toggle") {
      cin >> input;
      BIT = BIT ^ (1 << input);
      continue;
    }
  }
}
```
--- 
## 그리디
강노 참고
항상 최적해가 되는 것은 아니다.


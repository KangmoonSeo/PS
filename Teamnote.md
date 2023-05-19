# Teamnote for PS
- c++17 기준으로 작성했습니다. 
<!-- update: 23.05.19. -->
 
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
큰 문제 `DP[N]`을 작은 하위 문제로 나눈 후 작은 문제를 먼저 해결하고, 이를 통해 중복 계산을 피하며 최적해를 찾는 설계 기법이다.

`DP[0] > DP[1] > ... > DP[N]` 순으로 최적해를 찾는다. 이때 `DP[k]` 최적해 계산에 `DP[k-1]` 하위의 최적해를 사용한다. 

bottom-up 방식이다.  

--- 
## 그래프 이론
- 정점: V = Vertex 또는 arc
- 간선: E = Edge 또는 node
- 가중치: W = Weight

### 그래프의 표현
1. Adjacency Matrix
```cpp
int adj[100001][100001]; // 가중치가 없다면 bool
adj[v1][v2] = val;
```

2. Adjacency list
```cpp
vector<pair<int, int> > adj[100001];  // 가중치가 없다면 vector<int>
adj[v1].push_back(make_pair(val, v2)); // 또는 make_pair(v2, val)
```

--- 
## 그래프 탐색
> 깊이 우선 탐색(DFS), 너비 우선 탐색(BFS)

`visited[n]` 배열로 정점 방문 여부를 표현하고, 중복 방문을 피한다.

```cpp
bool visited[100001] = {}; // false로 초기화
```
### DFS
그래프의 깊은 부분을 우선적으로 탐색하는 알고리즘이다. 

시작 정점에서 한 방향으로 최대한 깊게 이동하다가 더 이상 진행할 수 없을 때, 다른 분기로 돌아와 탐색을 진행한다.

스택이나 재귀 호출을 이용하여 구현할 수 있으며, 백트래킹과 함께 활용된다.

### BFS

그래프의 가까운 부분을 우선적으로 탐색하는 알고리즘이다. 

시작 정점에서 인접한 정점들을 모두 탐색한 후, 탐색되지 않은 정점을 큐에 넣고 순서대로 탐색한다. 

큐를 이용하여 구현할 수 있으며, 최단 거리 문제에 자주 응용된다. 

#### BFS 예시 - 2차원 그래프 전염

```cpp
const int dy[4] = {1, 0, -1, 0};
const int dx[4] = {0, 1, 0, -1};

void contam(vector<vector<int> >& arr) {
  for (int j = 1; j <= y; j++) {
    for (int i = 1; i <= x; i++) {
      if (arr[j][i] == 1) {
        q.push(make_pair(j, i));
      }
    }
  }
  // bfs
  queue<pair<int, int> > q;
  int ans = 0;
  
  while (!q.empty()) {
    pair<int, int> p = q.front();
    int py = p.first;
    int px = p.second;
    ans = arr[py][px];
    q.pop();
    for (int d = 0; d < 4; d++) {
      if (arr[py + dy[d]][px + dx[d]] == 0) {
        arr[py + dy[d]][px + dx[d]] = ans + 1;
        q.push(make_pair(py + dy[d], px + dx[d]));
      }
    }
  }
  // exception
  for (int j = 1; j <= y; j++) {
    for (int i = 1; i <= x; i++) {
      if (arr[j][i] == 0) {
        cout << "-1\n";
        return;
      }
    }
  }
  // ans
  cout << ans << "\n";
}
```

--- 
## 최단거리
: 가중치 방향그래프에서, 정점 쌍 사이의 최단 경로를 찾는 알고리즘
- 단일 출발점 1:N 방식, 모든 정점 사이의 경로 N:N 방식으로 나눌 수 있음
- 활용: 도시 간의 최단 경로, 항공 노선 최적화 

#### 1:N 
: 단일 출발점에서 모든 정점까지의 최단 경로를 찾는 알고리즘. 다익스트라:`O(ElogV)`, 벨만-포드:`O(EV)`로 구현 가능

#### N:N
: 모든 정점 쌍 사이의 최단 경로를 찾는 알고리즘. 플로이드-워셜:`O(V^3)`로 구현 가능

### 다익스트라 (1:N)
> 시간복잡도: O(ElogV)
 
단일 출발점에서 모든 정점까지의 최단 경로를 찾는 알고리즘이다.

각 정점까지의 현재까지의 최단 거리를 유지하며 그리디한 방식으로 탐색하여 최단 경로를 계산한다.

이때 가중치는 음수가 될 수 없다. 최단거리 알고리즘 중 속도가 빠른 편이다. 

- input: 출발점 `start`, V개의 vector<pii> sequence를 저장하는 adjacency list `adj`, 연결이 끊긴 간선은 INF로 초기화 되어있음
- output: 출발점 start에서 i까지의 최단거리 `dist[i]`, 연결이 끊긴 간선은 `INF`로 초기화 되어있음

 ```cpp
typedef pair<int, int> pii;
vector<pii> adj[MAX_V];  // V개의 pii sequence를 저장하는 adj List
int dist[MAX_V]; // 연결되지 않은 Edge = INF
 
void dijkstra(int start) {
  fill_n(dist, MAX_V, INF);

  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push(make_pair(0, start)); // push { distance, vertex }
  dist[start] = 0; // 자기 자신까지의 거리는 0

  while (!pq.empty()) {
    int cur = pq.top().vertex;
    int cur_dist = pq.top().distance;
    pq.pop();
 
    if (dist[cur] < cur_dist) continue; // 저장된 dist가 queue에서 꺼낸 dist보다 작으면 skip
                             
    for (pii p : adj[cur]) { // 시작점이 cur인 adj list에서 pair를 순서대로 가져옴
      int new_dist = p.distance + cur_dist;
      if (new_dist < dist[p.vertex]) { // 새 dist가 저장된 dist보다 작으면 update
        dist[p.vertex] = new_dist;
        pq.push(make_pair(new_dist, p.vertex));  // queue에 pair push
      }
    }
  }
}
 ```
 
### 벨만-포드 (1:N)
> 시간복잡도: O(EV)
음수 포함 실수의 가중치를 가진 그래프에서, 단일 출발점에서 모든 정점까지의 최단 경로를 찾는 DP 기반 알고리즘이다.

각 정점까지의 최단 거리를 추정하고 이를 반복적으로 업데이트하여 최단 경로를 계산한다.

다익스트라:O(ElogV) 대비 느리지만:O(EV), 음수를 다룰 수 있다. 

- input: 출발점 `start`, V개의 vector<pii> sequence를 저장하는 adjacency list `adj`, 연결이 끊긴 간선은 INF로 초기화 되어있음
- output: 출발점 start에서 i까지의 최단거리 `dist[i]`, 연결이 끊긴 간선은 `INF`로 초기화 되어있음
 
```cpp
typedef pair<long long, int> pii;
vector<pii> adj[MAX_V];  // V개의 pii sequence를 저장하는 adj List
int dist[MAX_V]; // 연결되지 않은 Edge = INF

int bellman(int start) { // return -1: 음수 사이클 발생 시 비정상 종료
  fill_n(dist, MAX_V, INF);
  dist[start] = 0; // 자기 자신까지의 거리는 0

  for (int i = 1; i <= n; i++) {
    for (int cur = 1; cur <= n; cur++) {
      if (dist[cur] == INF) continue;
      for (pii p : adj[cur]) { // 시작점이 cur인 adj list에서 pair를 순서대로 가져옴
        long long new_dist = p.distance + dist[cur];
        if (new_dist < dist[p.vertex]) { // 새 dist가 저장된 dist보다 작으면 update
          dist[p.vertex] = new_dist; 
          if (i == n) return -1;  // 음수 사이클 발생
        }
      }
    }
  }
  return 1; // 정상 종료
}
```
### 플로이드-워셜 (N:N)
> 시간복잡도: O(V^3)
모든 정점 쌍 사이의 최단 경로를 찾는 DP 기반의 알고리즘이다. 

모든 정점을 중간 경유지로 사용하여(구현 부 k loop) 시작 정점에서 도착 정점으로 가는 최단 경로를 계산한다. 

알고리즘은 각 단계마다 현재까지의 최단 경로를 유지하면서 모든 정점 쌍에 대해 갱신을 수행한다. 
 
- input: 가중치 방향그래프 W[n][n], 연결이 끊긴 간선은 INF로 초기화 되어있음
- output: i에서 j로 가는 최소 비용을 담은 배열 D[n][n]

 ```cpp
void floid(vector<vector<int>>& W, vector<vector<int>>& D) {
  D = W; // 초기 값 D_(k=0) = D_0
  for (int k = 1; k <= n; k++) { // D_1, D_2, ... , D_n; D_k 계산에 D_k-1를 사용함
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (i == j) continue;
        D[i][j] = min(D[i][j], D[i][k] + D[k][j]);  // k를 중간 경유지로 사용
      }
    }
  }
}
 ```

--- 
## 백트래킹

백트래킹 알고리즘은 가능한 모든 후보 해를 탐색하면서 해를 찾는 알고리즘이다. 
 
주어진 조건을 만족하는 해를 찾기 위해 한 후보를 선택하고, 해당 후보가 조건을 만족하지 않으면 이전 상태로 돌아가 다른 후보를 선택하는 방식으로 진행된다. 
  
이러한 되추적(backtracking)을 통해 모든 가능성을 조사하며 해를 찾는데 사용된다.
                            
#### 백트래킹 예시 - N과 M; 수열 오름차순 경우의 수 찾기 

```cpp
void BT(int init = 0) {
  if (init == m) {
    int length = bt.size();
    for (int i = 0; i < length; i++) {
      cout << bt[i] << " ";
    }
    cout << "\n";
    return;
  }
  int b;
  if (bt.empty()) {
    b = 0;
  } else {
    b = bb[bt.back()];
  }
  for (int i = b; i < n; i++) {
    bt.push_back(field[i]);
    BT(init + 1);
    bt.pop_back();
  }
}
```
--- 
## 비트마스킹
1 << 4 == 1000(2) == 16

비트마스킹 알고리즘은 정수의 이진 표현을 활용하여 집합을 표현하고 조작하는 기법이다. 
     
이를 통해 집합 연산을 비트 연산으로 처리하여 성능을 향상시킬 수 있다. 
     
주로 집합에서 각 원소를 고유한 비트 위치에 매핑하여, 해당 원소의 포함 여부를 비트 값으로 나타낸다. 
     

#### 비트마스킹 예시 - 집합 다루기

비어있는 공집합 S가 주어졌을 때, 아래 연산을 수행하는 프로그램을 작성하시오.

- add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.   
- remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
- check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
- toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
- all: S를 {1, 2, ..., 20} 으로 바꾼다.
- empty: S를 공집합으로 바꾼다. 
     
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
 
최적해를 구하기 위해 각 단계에서 지금 당장 가장 좋은 선택을 하는 알고리즘이다. 
 
이후의 선택에 대한 영향을 고려하지 않고 일관되게 가장 유리한 선택을 고른다. 

그리디 알고리즘으로 구한 해가 항상 최적해가 아니므로 적용 가능한 예시임을 확. 
 
그리디 해가 최적해임이 보장된다면, 해당 방법을 통해 각 단계에서의 선택들을 합쳐 전체적인 문제의 최적해를 찾을 수 있다.

 #### 그리디 적용 예시
 > 그러나 문제의 특성에 따라 다른 알고리즘들이 필요할 수도 있으므로, 문제를 해결할 때에는 그리디 알고리즘이 항상 최적해를 보장하는지 여부를 신중히 고려해야 합니다.
 
1. 최소 동전 거슬러주기 (Minimum Coin Change): 동전의 종류와 거슬러 주어야 할 금액이 주어졌을 때, 거슬러주는 동전의 개수를 최소화하는 문제에서 그리디 알고리즘이 최적해를 보장합니다.

2. 최대 부분 배열 합 (Maximum Subarray Sum): 배열에서 연속된 부분 배열의 합 중 가장 큰 값을 찾는 문제에서 그리디 알고리즘이 최적해를 보장할 수 있습니다.

3. 최소 신장 트리 (Minimum Spanning Tree): 그래프에서 모든 정점을 포함하면서 간선의 가중치 합이 최소인 트리를 찾는 문제에서 크루스칼 알고리즘과 프림 알고리즘이 그리디 알고리즘이 최적해를 보장합니다.

4. 태스크 스케줄링 (Task Scheduling): 여러 태스크가 주어진 시간 내에 완료되도록 스케줄링하는 문제에서 최단 처리 시간이나 마감 시간에 따라 그리디 알고리즘이 최적해를 보장할 수 있습니다.

5. 최대 회의 수 (Maximum Meetings): 회의의 시작 시간과 종료 시간이 주어졌을 때, 겹치지 않고 최대한 많은 회의를 선택하는 문제에서 그리디 알고리즘이 최적해를 보장할 수 있습니다.

6. 최소 절단 문제 (Minimum Cut Problem): 그래프에서 두 개의 그룹으로 정점을 분할하는데 필요한 최소 간선 수를 찾는 문제에서 그리디 알고리즘이 최적해를 보장할 수 있습니다.

7. 행렬 체인 곱셈 (Matrix Chain Multiplication): 여러 행렬의 곱셈 순서를 결정하여 곱셈 연산의 총 수를 최소화하는 문제에서 그리디 알고리즘이 최적해를 보장할 수 있습니다.

8. 간선 가중치 합 최소화 (Minimum Edge Weight Sum): 그래프에서 모든 정점을 연결하는 최소 비용의 간선 집합을 찾는 문제에서 프림 알고리즘이 그리디 알고리즘이며 최적해를 보장합니다.
 ---


# team-note for PS
- c++17 기준으로 작성했습니다. 
<!-- update: 23.07.02. -->
 
## 목차
0. [기본 함수](#기본-함수-및-구현)
1. [누적합](#누적합) <!-- 2. [구현](#구현) -->
2. [DP](#dp)
3. [그래프 이론](#그래프-이론)
4. [그래프 탐색](#그래프-탐색)<!-- 5. [트리순회](#트리순회) -->
5. [최단거리](#최단거리) <!-- 6. [완전탐색](#완전탐색) -->
6. [최소 신장 트리](#최소-신장-트리)
7. [백트래킹](#백트래킹)
8. [비트마스킹](#비트마스킹)
9. [그리디](#그리디)
10. [투 포인터](#투-포인터)
<!-- 10. [라인스위핑](#라인스위핑) --> <!-- 12. [LIS](#lis) --><!--9. [이분탐색](#이분탐색)--> <!-- 11. [펜윅트리](#펜윅트리) -->

## 기본 함수 및 구현
- FastIO
```cpp
ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); /* FastIO */
```

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

- N까지의 소수 구하기 : 에라토스테네스의 체
> 시간복잡도 : O( n loglogn )
```cpp
vector<int> getPrime(int n) {
  vector<int> set;
  vector<bool> isPrime(n + 1, true);
  set.push_back(2);
  for (int i = 3; i <= n; i += 2) { // 2의 배수 탐색 X
    if (!isPrime[i]) continue;
    set.push_back(i);
    if (i > sqrt(n)) continue;
    for (int j = i * i; j <= n; j += i) isPrime[j] = false;
  }
  return set;
}
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

스택이나 재귀 호출을 이용하여 구현할 수 있으며, 백트래킹과 함께 활용할 수 있다.

### BFS

그래프의 가까운 부분을 우선적으로 탐색하는 알고리즘이다. 

시작 정점에서 인접한 정점들을 모두 탐색한 후, 탐색되지 않은 정점을 큐에 넣고 순서대로 탐색한다. 

큐를 이용하여 구현할 수 있으며, 최단 거리 문제에 자주 응용된다. 

#### BFS - 2차원 그래프 전염

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
 #### dijkstra에서의 경로 추적
 
 각 정점의 부모를 기록해 두고, 이를 역추적하면 경로를 알 수 있다. // O(n)
 ```cpp
 // ...
     if (new_dist < dist[p.vertex]) { 
        dist[p.vertex] = new_dist;
        parent[p.second] = cur; // new!
        pq.push(make_pair(new_dist, p.vertex));  
      }
 // ...
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
## 최소 신장 트리
: MST(Minimum Spanning Tree)

**신장 트리**는 무방향 그래프에서 모든 정점을 포함하는 간선을 선택하여 만들어짐

이때 간선의 개수는 V-1개이며, 각 간선의 가중치 존재 여부는 상관하지 않음

**최소 신장 트리**는 무방향 가중 그래프에서, 신장 트리를 이루는 간선의 가중치 합이 최소인 경우를 가르킴

하나의 무방향 가중 그래프는 여러 가지의 최소 신장 트리를 가짐. 즉 최소 신장 트리는 유일하지 않음

### 최소 신장 트리의 구현

가중치 무방향 그래프를 이루는 간선 집합에서 비용이 최소인 간선 중 적합한 경우를 선별하여 최소 신장 트리로 만듦

- input: 가중치 무방향 그래프의 간선 집합 
- output: 최소 신장 트리의 간선 집합 (또는 최소 신장 트리의 root)

최소 신장 트리는 Kruskal 알고리즘, Prim 알고리즘으로 구현할 수 있음

### 크루스칼
> 시간복잡도: O(ElogV)
 
모든 정점을 개별적인 트리로 선언한 후, V-1번의 유니온 파인드로 트리를 병합해나가는 알고리즘

초기에 모든 정점은 root node가 되는 트리로 변환됨, V-1번의 반복문에서 비용이 최소인 간선에 대해 검증을 거침

최소 비용 간선의 시작 노드가 u, 도착 노드가 v일 때 먼저 u와 v의 트리가 같은 트리인지 검증함 (root가 같으면 같은 트리)

만약 두 트리가 다른 트리라면 유니온 파인드로 u가 포함된 트리와 v가 포함된 트리를 병합함

즉, 시작 노드와 도착 노드의 root가 다른 경우에만 병합 과정이 일어남 (동일 트리 내에 있다면 병합하지 않음)


#### 분리 집합 (유니온 파인드)
: disjoint set (union find)
> 시간복잡도: 최적화시 O(α(N)) ~ O(1)

- `p[u]` : 트리의 부모 번호, `p[u] == -1`인 경우 노드 u가 root임이 보장됨

- `h[u]` : **root가 u인 트리**의 높이, 두 트리의 높이를 비교하여 높이가 낮은 트리가 높은 트리에 병합됨

- `void find_root(int u)` : p[u] == -1이 될 때 까지 함수를 재귀적으로 호출해 root의 번호를 불러오는 함수

- `bool union_root(int u, int v)` : u 트리와 v 트리가 같은 트리면 tree를 반환하고, 다른 트리면 병합한 후 false를 반환하는 함수

```cpp
int p[MAX_V];       // saves parent number, -1: root
int h[MAX_V] = {};  // height
int find_root(int u) {
  if (p[u] == -1) return u; // p[u] == -1 <-> 자신이 root임
  p[u] = find_root(p[u]);
  return p[u];
}
bool union_root(int u, int v) {
  u = find_root(u); 
  v = find_root(v);
  if (u == v) return true; // it is same tree
  if (h[u] > h[v]) swap(u, v); // h[u] < h[v]로 만듦
  p[u] = v;
  if (h[u] == h[v]) h[v]++;
  return false; // union completed
}
void solve() {
  fill_n(p, MAX_V, -1); // 초기에 모든 정점을 root로 만듦
  int u, v;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    if (union_root(u, v)) {  
      // 병합이 일어났을 때 실행되는 block
    }
  }
  //
}
```

#### 크루스칼 알고리즘 구현
- input: 가중치 무방향 그래프의 간선 집합 (edge)
- output: 최소 신장 트리의 가중치 합 (ans)

```cpp
int n, m;
pair<int, pair<int, int> > edge[MAX_E]; // { w, {u, v} }
int p[MAX_V];       // saves parent number
int h[MAX_V] = {};  // height
int find_root(int u) {
  if (p[u] == -1) return u;
  p[u] = find_root(p[u]);
  return p[u];
}
bool union_root(int u, int v) {
  u = find_root(u);
  v = find_root(v);
  if (u == v) return true;
  if (h[u] > h[v]) swap(u, v);
  p[u] = v;
  if (h[u] == h[v]) h[v]++;
  return false;
}
void solve() {
  int ans = 0;
  // kruskal with disjoint set
  fill_n(p, MAX_V, -1);
  sort(edge, edge + MAX_E);
  int cnt = 0;
  for (int i = 0; i < m; i++) {
    pair<int, pair<int, int> > e = edge[i];
    int w = e.first;
    int u = e.second.first; 
    int v = e.second.second;  
    if (union_root(u, v)) continue; // disjoint set
    ans += w; // 가중치의 합을 구함
    if (cnt++ >= n - 1) break; // n-1
  }
  cout << ans << "\n";
}
```

### 프림 (with priority queue)
> 시간복잡도: O(V^2) 또는 O(ElogV)

트리를 하나의 정점에서 시작, 주변 간선 중 최소 가중치를 선택해 확장해나가는 그리디 알고리즘

`dist[u]` 배열을 선언하여 루프를 V-1번 반복, 루프마다 트리부터 트리 근처 정점까지의 거리를 갱신함

이때 dist가 최소인 간선과 그 도착점을 지정, 트리에 병합함

최소 신장 트리에 포함되는 정점은 `visited[u]`값을 true로 전환

--- 
## 백트래킹

백트래킹 알고리즘은 가능한 모든 후보 해를 탐색하면서 해를 찾는 알고리즘이다. 
 
주어진 조건을 만족하는 해를 찾기 위해 한 후보를 선택하고, 해당 후보가 조건을 만족하지 않으면 이전 상태로 돌아가 다른 후보를 선택하는 방식으로 진행된다. 

이러한 되추적(backtracking)을 통해 모든 가능성을 조사하며 해를 찾는데 사용된다.

보통 전역변수의 값을 수정하면서 종결 조건을 찾아가고, 재귀마다 종결 조건을 체크하여 종결 시점에 함수를 return한다. 

#### 백트래킹 - N과 M; 수열 오름차순 경우의 수 찾기 

```cpp
void BT(int init = 0) {
  if (init == m) { // 종결 조건
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

#### 백트래킹 - 스도쿠 채워나가기 (BOJ 2580)
```cpp
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

int arr[9][9];
priority_queue<pipii, vector<pipii>, greater<pipii> > pq; // zero points are here

bool setNumber() {
  if (pq.empty()) { // termination condition
    return true;
  }
  pii p = pq.top().second;
  pq.pop();
  vector<int> vec = recommend(p); // recommend candidates of point
  for (int it : vec) {
    arr[p.y][p.x] = it;
    if (setNumber()) return true;
  }
  // reset
  arr[p.y][p.x] = 0;  
  pq.push({vec.size(), p}); // {weight, point}
  return false;
}
```


--- 
## 비트마스킹
`1 << 4 == 16`

비트마스킹 알고리즘은 정수의 이진 표현을 활용하여 집합을 표현하고 조작하는 기법이다. 
     
이를 통해 집합 연산을 비트 연산으로 처리하여 성능을 향상시킬 수 있다. 
     
주로 집합에서 각 원소를 고유한 비트 위치에 매핑하여, 해당 원소의 포함 여부를 비트 값으로 나타낸다. 
     

#### 비트마스킹 - 집합 다루기

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

그리디 알고리즘으로 구한 해가 항상 최적해가 아니므로 적용 가능한 예시임을 확인할 수 있다. 
 
그리디 해가 최적해임이 보장된다면, 해당 방법을 통해 각 단계에서의 선택들을 합쳐 전체적인 문제의 최적해를 찾을 수 있다.

 #### 그리디 알고리즘 적용

 > 그러나 문제의 특성에 따라 다른 알고리즘들이 필요할 수도 있으므로, 문제를 해결할 때에는 그리디 알고리즘이 항상 최적해를 보장하는지 여부를 신중히 고려해야 합니다.
 
1. 거스름돈 문제: 가장 적은 수의 동전으로 거스름돈을 주는 문제에서는 큰 단위의 동전부터 우선적으로 사용하면 최적해를 얻을 수 있습니다.

2. 활동 선택 문제: 주어진 일련의 활동 중에서 최대한 많은 활동을 선택하는 문제에서는 끝나는 시간이 가장 이른 활동을 선택하면 최적해를 얻을 수 있습니다.

3. 허프만 코딩(Huffman coding): 문자열 압축에서 가장 빈도가 높은 문자에 가장 짧은 비트를 할당하여 효율적인 압축을 구현하는데 그리디 알고리즘이 사용됩니다.

4. 최소 신장 트리(MST): Kruskal의 알고리즘과 Prim의 알고리즘은 각각 그리디 알고리즘의 예시로, 최소 신장 트리를 찾는 문제에서 최적해를 제공합니다.

5. 다익스트라 알고리즘: 최단 경로 문제에서 출발점으로부터 가장 가까운 노드를 선택하여 점진적으로 최단 경로를 구하는 그리디 알고리즘입니다.

6. 커버 센서 문제: 센서를 가장 적은 수로 사용하여 모든 영역을 커버하는 문제에서, 센서의 위치를 그리디하게 선택하면 최적해를 얻을 수 있습니다.

7. 분할 가능한 배낭 문제: 일부 배낭 문제에서는 무게 대비 가치가 높은 물건을 우선적으로 선택하여 최적해를 얻을 수 있습니다.

8. 최대 감소 부분 수열 문제: 주어진 수열에서 최대한 많은 수를 선택하되, 선택한 수들의 값이 감소하는 부분 수열을 찾는 문제에서 그리디 알고리즘이 최적해를 제공할 수 있습니다.

9. 타임 테이블 스케줄링 문제: 주어진 일련의 이벤트 중에서 가장 빨리 끝나는 이벤트를 선택하여 최적해를 찾을 수 있습니다.

10. 최대 수익 문제: 주어진 가격과 판매량으로 이루어진 상품 목록에서, 가격이 가장 높은 상품을 우선적으로 선택하여 최대 수익을 얻을 수 있습니다.
 ---

## 투 포인터
> 시간복잡도 : O(N) 

: 정렬된 리스트에서, 최적해를 두 점 left와 right의 위치를 1칸씩 바꿔가며 찾는 알고리즘
- 항상 left < right / left in [0,n) / right in [0,n) 여야 함
- `l = 0, r = 0` 로 시작하면 조건에 따라 `l++, r++`
- `l = 0, r = n - 1` 로 시작하면 조건에 따라 `l++, r--`
- O(N^2) 완전 탐색과 비교했을 때 시간 복잡도가 O(N)으로 효율이 좋음
  
#### 투 포인터 - 좋다(1253)
> 시간복잡도 : O(N^2)

- n개의 숫자 중에서, 두 숫자의 합으로 표현되는 숫자의 개수를 세는 문제 `N <= 2000`
- 비교군이 되는 숫자 i를 0부터 n-1까지 설정한 후 `O(N)`, l과 r의 포인터를 옮겨가며 후보를 찾아나감 `O(N)`
  
```cpp
typedef long long ll;

void solve() {
  sort(arr, arr + n); // must be sorted, O(NlogN)
  int cnt = 0;
  for (int i = 0; i < n; i++) { // O(N)
    int l = 0, r = n - 1;  // two pointer initialzation
    while (l < r) { // O(N)
      ll sum = arr[l] + arr[r];
      if (sum == arr[i]) {
        if (l == i) l++;
        else if (r == i) r--;
        else {
          cnt++; 
          break;
        }
      } else if (sum < arr[i]) {
        l++;
      } else {
        r--;
      }
    }
  }
  cout << cnt << "\n";
}
``

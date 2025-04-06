from collections import deque

H, W = 12, 6
dy = [0, 1, 0, -1]
dx = [1, 0, -1, 0]

arr = [['.'] * (W + 2) for _ in range(H + 2)]
ans = 0


def bfs(y, x):
    visited = [[False] * (W + 2) for _ in range(H + 2)]
    q = deque()
    seq = []

    q.append((y, x))
    seq.append((y, x))
    visited[y][x] = True

    while q:
        cy, cx = q.popleft()
        for d in range(4):
            ny, nx = cy + dy[d], cx + dx[d]
            if visited[ny][nx]:
                continue
            if arr[ny][nx] == '.':
                continue
            if arr[ny][nx] == arr[y][x]:
                visited[ny][nx] = True
                q.append((ny, nx))
                seq.append((ny, nx))

    if len(seq) < 4:
        return False

    for py, px in seq:
        arr[py][px] = '.'
    return True


def crack():
    flag = False
    for y in range(1, H + 1):
        for x in range(1, W + 1):
            if arr[y][x] != '.' and bfs(y, x):
                flag = True
    return flag


def falldown():
    for x in range(1, W + 1):
        for y in range(1, H):
            if arr[y][x] == '.':
                for k in range(y + 1, H + 1):
                    if arr[k][x] != '.':
                        arr[y][x], arr[k][x] = arr[k][x], arr[y][x]
                        break


def solve():
    global ans
    while crack():
        ans += 1
        falldown()
    print(ans)


if __name__ == "__main__":
    for y in range(H, 0, -1):
        line = input()
        for x in range(1, W + 1):
            arr[y][x] = line[x - 1]

    solve()

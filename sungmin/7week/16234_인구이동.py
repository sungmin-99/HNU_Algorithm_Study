from collections import deque
import sys

input = sys.stdin.readline

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def allience(x, y):
    q = deque()
    q.appendleft((x, y))
    while q:
        check = False
        x, y = q.pop()
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if not(0 <= nx < n and 0 <= ny < n):
                continue
            if not(l <= abs(graph[x][y] - graph[nx][ny]) <= r):
                continue
            if visit[nx][ny] == 0:
                visit[nx][ny] = 1
                q.appendleft((nx, ny))
                check = True
        if check:
            visit[x][y] = 1

n, l, r = map(int, input().split())
graph = []
for _ in range(n):
    graph.append(list(map(int, input().split())))

ans = 0
while True:
    visit = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if visit[i][j] == 0:
                allience(i, j)

    a = [0, 0, 0]
    check = 0
    for i in range(n):
        for j in range(n):
            if visit[i][j] == 1:
                a[0] += graph[i][j]
                a[1] += 1
                if check == graph[i][j]:
                    a[2] += 1
                check = graph[i][j]
    if a[1] == a[2]:
        break
    b = a[0] // a[1]
    for i in range(n):
        for j in range(n):
            if visit[i][j] == 1:
                graph[i][j] = b
    ans += 1
    for i in range(n):
        print(visit[i])
print(ans)
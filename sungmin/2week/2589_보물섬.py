from collections import deque
import sys
input = sys.stdin.readline

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def bfs(x, y):
    q = deque()
    q.appendleft((x, y))
    visit[x][y] = 1
    while q:
        x, y = q.pop()
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            if visit[nx][ny] == 0 and graph[nx][ny] == 'L':
                q.appendleft((nx, ny))
                visit[nx][ny] = visit[x][y] + 1
    return visit[x][y] - 1

n, m = map(int, input().split())
graph = []
for _ in range(n):
    graph.append(input())

ans = 0
for i in range(n):
    for j in range(m):
        if graph[i][j] == 'L':
            visit = [[0] * m for _ in range(n)]
            ans = max(ans, bfs(i, j))
print(ans)
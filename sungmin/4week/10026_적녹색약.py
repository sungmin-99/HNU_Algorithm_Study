from collections import deque

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
      if not(0 <= nx < n and 0 <= ny < n) or visit[nx][ny]:
        continue
      if graph[nx][ny] == graph[x][y]:
        q.appendleft((nx, ny))
        visit[nx][ny] = 1
  return

def bfs2(x, y):
  q = deque()
  q.appendleft((x, y))
  visit[x][y] = 1
  while q:
    x, y = q.pop()
    for i in range(4):
      nx, ny = x + dx[i], y + dy[i]
      if not(0 <= nx < n and 0 <= ny < n) or visit[nx][ny]:
        continue
      if (graph[x][y] == 'R' or graph[x][y] == 'G') and (graph[nx][ny] == 'R' or graph[nx][ny] == 'G'):
        q.appendleft((nx, ny))
        visit[nx][ny] = 1
      elif graph[x][y] == graph[nx][ny]:
        q.appendleft((nx, ny))
        visit[nx][ny] = 1
  return

graph = []
n = int(input())
for _ in range(n):
  graph.append(input())
visit = [[0] * n for _ in range(n)]
ans = 0
for i in range(n):
  for j in range(n):
    if not(visit[i][j]):
     bfs(i, j)
     ans += 1

visit = [[0] * n for _ in range(n)]
ans2 = 0
for i in range(n):
  for j in range(n):
    if not(visit[i][j]):
     bfs2(i, j)
     ans2 += 1

print(ans, ans2)
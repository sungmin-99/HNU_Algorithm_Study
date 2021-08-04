# 1. 적록색약
> 정답 코드
```python
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
```

<br>
<b>적록색약이 아닌경우와 적록색약인경우 bfs를 2번 돌린다.</b>
<br><br><br><br><br><br>

# 2. 등수 구하기
> 정답 코드
```python
import sys

n, point, p = map(int, input().split())
if n == 0:
    print("1")
    sys.exit()
arr = list(map(int, input().split()))
arr.append(point)
arr.sort(reverse=True)
ans = arr.index(point)
check = ans
for i in range(ans, n):
    if arr[i] == arr[i + 1]:
        check += 1
    else:
        break

if check <= p - 1:
    print(ans + 1)
else:
    print("-1")
```

<br>
<b>처음에 등수가 없을때를 고려하지 않아서 여러번 에러가 났다.
<br>check으로 같은점수가 있을 때 p범위를 넘어가는지 확인하고 ans + 1 또는 -1을 출력한다.</b>
<br><br><br><br><br><br>
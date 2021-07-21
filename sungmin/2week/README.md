# 1. 효율적인 해킹
> 1차시도
```python
from collections import deque
import sys
input = sys.stdin.readline

def bfs(x):
    q = deque()
    q.appendleft(x)
    visit[x] = 1
    while q:
        x = q.pop()
        for i in graph[x]:
            if not(visit[i]):
                q.appendleft(i)
                visit[i] = visit[x] + 1
    return visit[x]

n, m = map(int, input().split())
graph = [[] for _ in range(n + 1)]
for _ in range(m):
    x, y = map(int, input().split())
    graph[y].append(x)

ans = []
for i in range(1, n + 1):
    visit = [0] * (n + 1)
    ans.append([i, bfs(i)])

ans.sort(key = lambda x:-x[1])
print(ans[0][0], end = " ")
for i in range(1, len(ans)):
    if ans[i - 1][1] == ans[i][1]:
        print(ans[i][0], end = " ")
    else:
        break
```
<br>
<b>틀린이유 : 방문한 순서를 답으로 설정했지만 방문한 순서가 아니라 방문한 갯수가 답이 되어야 된다.</b>
<br><br><br><br><br><br>

> 정답
```python
from collections import deque
import sys
input = sys.stdin.readline

def bfs(x):
    q = deque()
    q.appendleft(x)
    visit[x] = 1
    cnt = 0
    while q:
        x = q.pop()
        for i in graph[x]:
            if not(visit[i]):
                q.appendleft(i)
                visit[i] = 1
                cnt += 1
    return cnt

n, m = map(int, input().split())
graph = [[] for _ in range(n + 1)]
for _ in range(m):
    x, y = map(int, input().split())
    graph[y].append(x)

ans = []
for i in range(1, n + 1):
    visit = [0] * (n + 1)
    ans.append([i, bfs(i)])

ans.sort(key = lambda x:-x[1])
print(ans[0][0], end = " ")
for i in range(1, len(ans)):
    if ans[i - 1][1] == ans[i][1]:
        print(ans[i][0], end = " ")
    else:
        break
```
<br>
<b> bfs로 방향그래프를 탐색하여 탐색하는 노드의 개수를 리턴해 비교한다.
<br>시간 초과로 sys.stdin.readline을 사용하고 pypy로 제출하였다.</b>
<br><br><br><br><br><br>

# 2. 보물섬
```python
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
```
<br>
<b>bfs와 브루트포스가 익숙하다면 쉽게 해결 가능한 문제<br>
1. 그래프의 노드가 'L'인 경우 모두 bfs를 돌려서 가장 먼 노드와의 거리를 측정한다.<br>
2. 그 중 가장 거리가 먼 값을 출력한다.</b>
<br><br><br><br><br><br>

# 3. 상자의 균형
```python
n, l = map(int, input().split())
box = list(map(int, input().split()))
box = box[::-1]

num = 0
check = True
for i in range(n - 1):
    num += box[i]
    if box[i + 1] - l < num / (i + 1) < box[i + 1] + l:
        continue
    else:
        check = False
        break

if check:
    print("stable")
else:
    print("unstable")
```

<br>
<b>상자를 맨 위에서부터 무게 중심이 바로 아래상자 안에 들어가는지 확인한다.
<br>문제를 잘 읽으면 쉬운 구현만으로 풀 수 있는 문제</b>
<br><br><br><br><br><br>
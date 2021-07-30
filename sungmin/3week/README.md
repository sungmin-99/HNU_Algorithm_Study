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
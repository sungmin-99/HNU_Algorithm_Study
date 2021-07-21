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
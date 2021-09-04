from collections import deque

def bfs(x):
    q = deque()
    q.appendleft(x)
    visit[x] = 0
    while q:
        x = q.pop()
        if x == b:
            return visit[x]
        for i in graph[x]:
            if visit[i] != 0:
                continue
            else:
                visit[i] = visit[x] + 1
                q.appendleft(i)
    return -1

n = int(input())
a, b = map(int, input().split())
m = int(input())
graph = [[] for _ in range(n + 1)]

for _ in range(m):
    x, y = map(int, input().split())
    graph[x].append(y)
    graph[y].append(x)
visit = [0] * (n + 1)

print(bfs(a))
from collections import deque
import sys
input = sys.stdin.readline

def bfs(x):
    q = deque()
    q.appendleft(x)
    pNode[x] = 1
    while q:
        x = q.pop()
        for i in graph[x]:
            if pNode[i] == 0:
                pNode[i] = x
                q.appendleft(i)
    return

n = int(input())
graph = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

pNode = [0] * (n + 1)
bfs(1)
for i in range(2, n + 1):
    print(pNode[i])
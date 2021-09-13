# 1. 최단경로
> 정답 코드
```python
import heapq
import sys
input = sys.stdin.readline
INF = int(1e9)

def dijkstra(start):
    q = []
    heapq.heappush(q, (0, start))
    distance[start] = 0
    while q:
        dist, now = heapq.heappop(q)
        if distance[now] < dist:
            continue
        for i in graph[now]:
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))

v, e = map(int, input().split())
k = int(input())
graph = [[] for _ in range(v + 1)]
for _ in range(e):
    a, b, t = map(int, input().split())
    graph[a].append((b, t))
distance = [INF] * (v + 1)

dijkstra(k)

for i in range(1, v + 1):
    if distance[i] == INF:
        print("INF")
    else:
        print(distance[i])
```

<br>
<b>다익스트라 알고리즘</b>
<br>
![dijkstra](./img/dijkstra.png)
<br>
우선순위 큐를 이용해서 cost가 적은 노드부터 탐색해서 시간복잡도를 단축한다.
<br><br><br><br><br><br>

from collections import deque
import sys
input=sys.stdin.readline

def bfs(graph,start,visited):
    queue=deque([start])
    visited[start]=True
    while queue:
        v=queue.popleft()
        index.append(v)
        for i in graph[v]:
            if not visited[i]:
                result.append(v)
                queue.append(i)
                visited[i]=True

n=int(input())
graph=[[] for i in range(n+1)]
result=[]
answer=[0]*(n-1)
index=[]
visited=[False]*(n+1)

for i in range(n-1):
    a,b=map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)
    
bfs(graph,1,visited)

for i in range(1,len(index)):
    answer[index[i]-2]=result[i-1]

for i in range(len(answer)):
    print(answer[i])
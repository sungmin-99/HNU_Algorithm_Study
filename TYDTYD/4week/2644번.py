INF=int(1e9) #무한을 의미하는 값

n=int(input())
a,b=map(int,input().split())
m=int(input())
graph=[[INF]*(n+1) for i in range(n+1)]

for i in range(1,n+1):
    for j in range(1,n+1):
        if a==b:
            graph[a][b]=0

for i in range(m):
    x,y=map(int,input().split())
    graph[x][y]=1
    graph[y][x]=1

for k in range(1,n+1):
    for g in range(1,n+1):
        for h in range(1,n+1):
            graph[g][h]=min(graph[g][h],graph[g][k]+graph[k][h])

answer=graph[a][b]

if answer>=INF:
    print(-1)
else:
    print(answer)
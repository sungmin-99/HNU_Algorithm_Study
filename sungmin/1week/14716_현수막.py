import sys
sys.setrecursionlimit(10**9)
def dfs(x, y):
    if x <= -1 or x >= n or y <= -1 or y >= m:
        return False

    if graph[x][y] == 1:
        graph[x][y] = 0
        for i in range(8):
            nx = x + dx[i]
            ny = y + dy[i]
            dfs(nx, ny)
        return True
    return False

n, m = map(int, input().split())
graph = []
for i in range(n):
    graph.append(list(map(int, input().split())))
dx = [1, -1, 0, 0, 1, -1, 1, -1]
dy = [0, 0, 1, -1, -1, 1, 1, -1]
ans = 0

for i in range(n):
    for j in range(m):
        if dfs(i, j) == True:
            ans += 1
print(ans)
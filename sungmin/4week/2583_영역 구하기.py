import sys
sys.setrecursionlimit(10000)

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def dfs(x, y):
    answer = 0
    if not(0 <= x < n and 0 <= y < m):
        return 0
    if graph[x][y] == 1:
        return 0
    graph[x][y] = 1
    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]
        answer += dfs(nx, ny)
    return answer + 1

m, n, k = map(int, input().split())
graph = [[0] * m for _ in range(n)]
for _ in range(k): # 그래프에 직사각형 찍어주기
    a, b, c, d = map(int, input().split())
    for i in range(a, c):
        for j in range(b, d): # 직사각형의 넓이
            graph[i][j] = 1

ans = []
for i in range(n): # 빈 공간 dfs로 찾기
    for j in range(m):
        if graph[i][j] == 0:
            ans.append(dfs(i, j))

ans.sort()
print(len(ans))
for i in range(len(ans)):
    print(ans[i], end = " ")
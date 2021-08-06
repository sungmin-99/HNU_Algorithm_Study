디지털티비
=============
    n = int(input())
    ch = []

    for _ in range(n):
        ch.append(input())

    a = ch.index('KBS1')
    A = a*'1'+a*'4'
    ch.pop(a)
    ch.insert(0,'KBS1')
    print(ch)
    b = ch.index('KBS2')
    B = b*'1'+ b*'4'
    print(ch)
    print(A+B)
    
등수구하기    
=============
    n, l, p = map(int, input().split())
    if n == 0:
        print(1)
    else:
        score = list(map(int, input().split()))
        score.append(l)
        score.sort(reverse=True)
        r = score.index(l) + 1
        if r > p or n==p and l == score[-1]:
            print(-1)

        else:
            print(r)
적록색약
=============
    import sys
    sys.setrecursionlimit(10**6)
    def bdfs(x, y):
        # 주어진 범위를 벗어나는 경우에는 즉시 종료
        if x <= -1 or x >= n or y <= -1 or y >= n:
            return False
        # 현재 노드를 아직 방문하지 않았다면
        if graph[x][y] == 'B':
            # 해당 노드 방문 처리
            graph[x][y] = 0
            # 상, 하, 좌, 우의 위치들도 모두 재귀적으로 호출
            bdfs(x - 1, y)
            bdfs(x, y - 1)
            bdfs(x + 1, y)
            bdfs(x, y + 1)
            return True
        return False

    def gdfs(x, y):
        # 주어진 범위를 벗어나는 경우에는 즉시 종료
        if x <= -1 or x >= n or y <= -1 or y >= n:
            return False
        # 현재 노드를 아직 방문하지 않았다면
        if graph[x][y] == 'G':
            # 해당 노드 방문 처리
            graph[x][y] = 1
            # 상, 하, 좌, 우의 위치들도 모두 재귀적으로 호출
            gdfs(x - 1, y)
            gdfs(x, y - 1)
            gdfs(x + 1, y)
            gdfs(x, y + 1)
            return True
        return False

    def rdfs(x, y):
        # 주어진 범위를 벗어나는 경우에는 즉시 종료
        if x <= -1 or x >= n or y <= -1 or y >= n:
            return False
        # 현재 노드를 아직 방문하지 않았다면
        if graph[x][y] == 'R':
            # 해당 노드 방문 처리
            graph[x][y] = 1
            # 상, 하, 좌, 우의 위치들도 모두 재귀적으로 호출
            rdfs(x - 1, y)
            rdfs(x, y - 1)
            rdfs(x + 1, y)
            rdfs(x, y + 1)
            return True
        return False

    def rgdfs(x, y):
        # 주어진 범위를 벗어나는 경우에는 즉시 종료
        if x <= -1 or x >= n or y <= -1 or y >= n:
            return False
        # 현재 노드를 아직 방문하지 않았다면
        if graph2[x][y] == 1:
            # 해당 노드 방문 처리
            graph2[x][y] = 0
            # 상, 하, 좌, 우의 위치들도 모두 재귀적으로 호출
            rgdfs(x - 1, y)
            rgdfs(x, y - 1)
            rgdfs(x + 1, y)
            rgdfs(x, y + 1)
            return True
        return False




    n = int(input())
    graph = []
    for _ in range(n):
        graph.append(list((input())))

    graph2 = graph[:]
    cntb = 0
    cntg = 0
    cntr = 0
    cntrg = 0
    for i in range(n):
        for j in range(n):
            if bdfs(i,j) == True:
                cntb += 1
            if rdfs(i,j) == True:
                cntr += 1
            if gdfs(i,j) == True:
                cntg += 1

    for k in range(n):
        for h in range(n):
            if  rgdfs(k,h) == True:
                cntrg += 1

    print(cntb+cntr+cntg, cntrg+cntb)

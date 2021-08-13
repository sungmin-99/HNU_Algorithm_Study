
촌수 구하기
=============
    import sys
    from collections import deque
    def bfs(graph, start, last, visited):
        # 큐(Queue) 구현을 위해 deque 라이브러리 사용
        queue = deque([start])
        # 현재 노드를 방문 처리
        visited[start] = 0
        # 큐가 빌 때까지 반복
        while queue:
            # 큐에서 하나의 원소를 뽑아 출력
            v = queue.popleft()
            # 해당 원소와 연결된, 아직 방문하지 않은 원소들을 큐에 삽입
            for i in graph[v]:
                if not visited[i]:
                    queue.append(i)
                    visited[i] = visited[v] + 1
            if visited[last]:
                print(visited[last])
                sys.exit()
        print(-1)
    n = int(input())
    start, last = map(int, input().split())
    k = int(input())
    graph = [[] for _ in range(n+1)]
    for _ in range(k):
        a, b = map(int,input().split())
        graph[a].append(b)
        graph[b].append(a)

    # 각 노드가 방문된 정보를 리스트 자료형으로 표현(1차원 리스트)
    visited = [False] * (n+1)
    # 정의된 BFS 함수 호출

    bfs(graph, start, last, visited)
    
기타연주 
=============
    from collections import deque
    import sys
    n, p = map(int, input().split())

    ls = deque(deque() for _ in range(n+1))

    cnt = 0
    for _ in range(n):
        i, j = map(int, sys.stdin.readline().split())
        if len(ls[i]) == 0:
            ls[i].append(j)
            cnt += 1
        else:
            if j > ls[i][-1]:
                ls[i].append(j)
                cnt += 1
            elif j == ls[i][-1]:
                continue
            else: #j < ls[i][-1]
                while len(ls[i]) != 0 and j < ls[i][-1]:
                    ls[i].pop()
                    cnt +=1
                if len(ls[i]) != 0 and j == ls[i][-1]:
                    continue
                ls[i].append(j)
                cnt += 1
    print(cnt)

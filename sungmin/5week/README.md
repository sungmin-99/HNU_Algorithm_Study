# 1. 동전
> 정답 코드
```python
n, k = map(int, input().split())
coins = []
for _ in range(n):
    coins.append(int(input()))
coins.sort()
dp = [0] * (k + 1)
dp[0] = 1

for coin in coins:
    for i in range(coin, k + 1):
        if i - coin >= 0:
            dp[i] += dp[i - coin]

print(dp[k])
```

<br>
<b>다이나믹 프로그래밍 문제</b>
<br> dp[i - coin]에서 구했던 경우의 수를 dp[i]에 더해주는 동적 할당
<br><br><br><br><br><br>

# 2. 촌수계산
> 정답 코드
```python
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
```

<br>
<b>그래프탐색 문제</b>
<br> 그래프를 a부터 탐색해서 b를 찾으면 그 순서를 반환한다.
<br> 그래프를 전부 돌아도 b가 나오지 않으면 두 노드가 연결되어 있지 않다고 생각하고 -1을 반환한다.
<br><br><br><br><br><br>

# 3. 토너먼트
> 정답 코드
```python
n, a, b = map(int, input().split())

ans = 0
while a != b:
    a -= a // 2
    b -= b // 2
    ans += 1

print(ans)
```

<br>
<b>브루트포스 문제</b>
<br> 브루트 포스라고 적혀있지만 그리디 문제에 가까운 것 같다. 조금만 생각해보며 어렵지 않은 문제
<br><br><br><br><br><br>

# 4. 외계인의 기타 연주
> 정답 코드
```python
import sys
input = sys.stdin.readline

n, p = map(int, input().split())

stack = [[] for _ in range(8)]
cnt = 0

for _ in range(n):
    a, b = map(int, input().split())
    while True:
        if stack[a] == []:
            stack[a].append(b)
            cnt += 1
            break
        elif stack[a][-1] == b:
            break
        elif stack[a][-1] > b:
            stack[a].pop()
            cnt += 1
            continue
        elif stack[a][-1] < b:
            stack[a].append(b)
            cnt += 1
            break

print(cnt)
```

<br>
<b>자료구조 스택 문제</b>
<br> 스택구조를 이해하고 활용하면 쉽게 해결 가능
<br><br><br><br><br><br>
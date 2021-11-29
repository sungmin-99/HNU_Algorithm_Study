# 1. 카드 구매하기
> 1차 시기
```python
n = int(input())
cards = list(map(int, input().split()))
value = 0
dp = [0] * (n + 1)

for i in range(len(cards)):
    card = i + 1
    if value <= cards[i] / card:
        value = cards[i] / card
        for j in range(card, n + 1):
            dp[j] = max(dp[j - card] + cards[i], dp[j])

print(dp[n])
```

<br>
<b>다이나믹 프로그래밍</b>
<br>각 카드의 마다 value 값을 설정하여 value가 높으면 dp를 초기화하고 낮으면 건너 띄는 알고리즘을 구성했다.
<br>한시간 동안 맞왜틀 하다가 value를 설정할 필요가 없다는 것을 깨달았다.
<br>크고 작은건 어짜피 컴퓨터가 계산해 주는것을...
<br><br><br>

> 정답
```python
n = int(input())
cards = list(map(int, input().split()))
dp = [0] * (n + 1)

for i in range(len(cards)):
    card = i + 1
    for j in range(card, n + 1):
        dp[j] = max(dp[j - card] + cards[i], dp[j])

print(dp[n])
```

<br>
<b>다이나믹 프로그래밍</b>
<br>코드를 수정할것도 없이 value만 삭제하니 귀신같이 맞았습니다가 나왔다...
<br><br><br><br><br><br>

# 2. 본대 산책
> 정답
```python
dp = [1, 0, 0, 0, 0, 0, 0, 0]

def walk(x):
    tmp = [0 for _ in range(8)]
    tmp[0] = x[1] + x[3]
    tmp[1] = x[0] + x[2] + x[3]
    tmp[2] = x[1] + x[3] + x[4] + x[5]
    tmp[3] = x[0] + x[1] + x[2] + x[5]
    tmp[4] = x[2] + x[5] + x[6]
    tmp[5] = x[3] + x[2] + x[4] + x[7]
    tmp[6] = x[4] + x[7]
    tmp[7] = x[5] + x[6]

    for i in range(8):
        tmp[i] = tmp[i] % 1000000007
    return tmp

for i in range(int(input())):
    dp = walk(dp)

print(dp[0])
```

<br>
<b>그래프탐색, 다이나믹 프로그래밍</b>
<br>그래프 탐색 문제인 줄 알고 선택했으나 그래프가 고정돼 있는 다이나믹 프로그래밍 문제였다.
<br><br><br>

# 3. 인구이동
> 1차 시기
```python
from collections import deque
import sys

input = sys.stdin.readline

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def allience(x, y):
    q = deque()
    q.appendleft((x, y))
    while q:
        check = False
        x, y = q.pop()
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if not(0 <= nx < n and 0 <= ny < n):
                continue
            if not(l <= abs(graph[x][y] - graph[nx][ny]) <= r):
                continue
            if visit[nx][ny] == 0:
                visit[nx][ny] = 1
                q.appendleft((nx, ny))
                check = True
        if check:
            visit[x][y] = 1

n, l, r = map(int, input().split())
graph = []
for _ in range(n):
    graph.append(list(map(int, input().split())))

ans = 0
while True:
    visit = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if visit[i][j] == 0:
                allience(i, j)

    a = [0, 0, 0]
    check = 0
    for i in range(n):
        for j in range(n):
            if visit[i][j] == 1:
                a[0] += graph[i][j]
                a[1] += 1
                if check == graph[i][j]:
                    a[2] += 1
                check = graph[i][j]
    if a[1] == a[2]:
        break
    b = a[0] // a[1]
    for i in range(n):
        for j in range(n):
            if visit[i][j] == 1:
                graph[i][j] = b
    ans += 1
    for i in range(n):
        print(visit[i])
print(ans)
```

<br>
<b>그래프탐색, 시뮬레이션</b>
<br>국경선을 개방하는 것까지는 문제 없는데 인구이동에서 문제가 발생한다...
<br>시뮬레이션 문제는 어디서 문제가 생긴지 알면서도 고치는게 쉽지 않다.
<br><br><br>

# 4. 이항 계수2
> 정답
```python
n, k = map(int, input().split())
dp = [[0] for i in range(1001)]
dp[1].append(1)
for i in range(2, 1001):
    for j in range(1, i + 1):
        if j == 1:
            dp[i].append(1)
        elif j == i:
            dp[i].append(1)
        else:
            dp[i].append(dp[i - 1][j - 1] + dp[i - 1][j])
print(dp[n + 1][k + 1] % 10007)
```

<br>
<b>다이나믹 프로그래밍</b>
<br>조합인 줄 알았는데 다이나믹 프로그래밍이였다.
<br><img src = "https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FzmTo7%2FbtqyTkFV9T1%2FMFwCDAm4NHLKKcQ9FwiZpk%2Fimg.jpg">
<br> 이 표를 생각하면 쉽게 구현할 수 있다.
<br><br><br>

test
# 1. 좋은 단어
> 1차시도
```python
n = int(input())
words = []
for _ in range(n):
    words.append(input())

cnt = 0
for i in range(n):
    stack = []
    check = True
    for j in words[i]:
        if stack == []:
            stack.append(j)
        elif j == 'A' and stack[-1] == 'A':
            stack.pop()
        elif j == 'B' and stack[-1] == 'B':
            stack.pop()
        elif len(stack) == 1:
            stack.append(j)
        else:
            check = False
            break
    if stack != []:
        check = False
    if check:
        cnt += 1
print(cnt)
```
<br>
<b>틀린이유 : 조건을 빼먹은 것 같은데 뭘 빼먹었는지 잘 모르겠다...</b>
<br><br><br><br><br><br>

> 정답 코드
```python
n = int(input())
words = []
for _ in range(n):
    words.append(input())

cnt = 0
for i in range(n):
    stack = []
    check = True
    for j in words[i]:
        if stack == []:
            stack.append(j)
        elif stack[-1] == j:
            stack.pop()
        else:
            stack.append(j)
    if not(stack):
        cnt += 1
print(cnt)
```

<br>
<b>빼먹은 조건을 찾을 수 없어서 단어의 문자와 스택의 문자가 같으면 pop하고 다르면 push하여 마지막에 스택이 비어있으면 True이고 스택이 비어 있지 않다면 False 이다.</b>
<br><br><br><br><br><br>

# 2. 회전하는 큐
> 정답코드
```python
from collections import deque

def left():
    x = q.popleft()
    q.append(x)
    return

def right():
    x = q.pop()
    q.appendleft(x)
    return

n, m = map(int, input().split())
numbers = list(map(int, input().split()))
q = deque()
for i in range(1, n + 1):
    q.append(i)

cnt = 0
for i in numbers:
    if q.index(i) > len(q) // 2:
        while q[0] != i:
            right()
            cnt += 1
        q.popleft()
    else:
        while q[0] != i:
            left()
            cnt += 1
        q.popleft()

print(cnt)
```
<br>
<b>원형큐를 구현하고 left를 해야되는지 right를 해야되는지 구분하면 쉽게 해결 가능한 문제</b>
<br><br><br><br><br><br>
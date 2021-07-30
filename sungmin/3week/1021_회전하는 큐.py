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
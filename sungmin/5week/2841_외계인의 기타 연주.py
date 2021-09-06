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
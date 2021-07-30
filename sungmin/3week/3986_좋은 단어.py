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
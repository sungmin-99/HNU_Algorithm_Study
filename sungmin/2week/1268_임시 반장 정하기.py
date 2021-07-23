n = int(input())
arr = []
for _ in range(n):
    arr.append(list(map(int, input().split())))
ans = [[i] for i in range(n)]
for k in range(5):
    for i in range(n):
        for j in range(i, n):
            if arr[i][k] == arr[j][k]:
                ans[i].append(j)
                ans[j].append(i)

answer = 0
check = 0
for i in range(n):
    setans = set(ans[i])
    if len(setans) > check:
        check = len(setans)
        answer = i + 1
print(answer)
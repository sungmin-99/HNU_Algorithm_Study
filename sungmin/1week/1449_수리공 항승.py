n, l = map(int,input().split())
leak = list(map(int,input().split()))
leak.sort()

cnt = 1
start = leak[0]
end = start + l - 0.5
for i in leak:
    if end >= i:
        continue
    else:
        cnt += 1
        end = i + l - 0.5

print(cnt)
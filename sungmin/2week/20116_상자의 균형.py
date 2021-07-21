n, l = map(int, input().split())
box = list(map(int, input().split()))
box = box[::-1]

num = 0
check = True
for i in range(n - 1):
    num += box[i]
    if box[i + 1] - l < num / (i + 1) < box[i + 1] + l:
        continue
    else:
        check = False
        break

if check:
    print("stable")
else:
    print("unstable")
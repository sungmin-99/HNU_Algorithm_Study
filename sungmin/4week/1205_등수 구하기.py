import sys

n, point, p = map(int, input().split())
if n == 0:
    print("1")
    sys.exit()
arr = list(map(int, input().split()))
arr.append(point)
arr.sort(reverse=True)
ans = arr.index(point)
check = ans
for i in range(ans, n):
    if arr[i] == arr[i + 1]:
        check += 1
    else:
        break

if check <= p - 1:
    print(ans + 1)
else:
    print("-1")
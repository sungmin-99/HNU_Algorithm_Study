n, l = map(int, input().split())
mid = list(map(int,input().split()))
mid.reverse()

ct = 0
for i in range(n-1):
    if sum(mid[0:i+1])/(i+1) >= mid[i+1]+l or sum(mid[0:i+1])/(i+1) <= mid[i+1]-l:
        ct += 1

if ct == 0:
    print("stable")
else:
    print("unstable")
    
    
    
    
import sys

n, l = map(int, input().split())
mid = list(map(int,input().split()))
mid.reverse()

total = 0
for i in range(n-1):
    total += mid[i]
    avg = total / (i + 1)
    if avg >= mid[i+1]+l or avg <= mid[i+1]-l:
        print("unstable")
        sys.exit()

print("stable")

import sys
input=sys.stdin.readline

n,k=map(int,input().split())
a=0
b=0

dp=[[] for i in range(1001)]

for i in range(len(dp)):
    a=0
    while(a<=b):
        if a==0 or a==b:
            dp[i].append(1)
        else:
            dp[i].append(dp[i-1][a]+dp[i-1][a-1])
        a=a+1
        if i==n and a==k+1:
            break
    if i==n and a==k+1:
        break
    b=b+1
    
print(dp[n][k]%10007)
n=int(input())
dp=[1,1]
answer=0
m=0

if n==1 or n==2:
    print(1)
else:
    n=n-2
    while(n>0):
        answer=1+sum(dp[:m+1])
        m=m+1
        dp.append(dp[m]+dp[m-1])
        n=n-1
    print(answer)

# 1 자기자신
# 10 자기자신
# 100 자기자신+1
# 1000 자기자신+1+10
# 10000 자기자신+1+10+100
# 100000 자기자신+1+10+100+1000
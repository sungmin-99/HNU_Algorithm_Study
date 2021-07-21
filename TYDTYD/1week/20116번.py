n,l=map(int,input().split())
x=[]
i=n
sum=0

x=[int(ch) for ch in input().split(' ')]

while(n>1):
    n=n-1
    sum=sum+x[n]
    if x[n-1]+l <= sum/(i-n) or x[n-1]-l >= sum/(i-n):
        print("unstable")
        n=-100

if n!=-100:
    print("stable")
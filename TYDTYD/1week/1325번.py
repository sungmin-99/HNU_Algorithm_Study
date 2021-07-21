n,m=map(int,input().split())
x=[]

for i in range(m):
    a,b=map(int,input().split())
    x[b].append(a)

print(x[:])
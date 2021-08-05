n,y,p=map(int,input().split())
if n>0:
    score=list(map(int,input().split()))
    index=0
    
    for i in range(n):
        if p==n and y==score[n-1] and index==0:
            index=index+1
            print(-1)
        if score[i]<y and i==p-1 and index==0:
            index=index+1
            print(i+1)
        elif score[i]<=y and i!=p-1 and index==0:
            index=index+1
            print(i+1)
        elif score[i]>y and i==n-1 and p>n and index==0:
            index=index+1
            print(n+1)
    if index==0:
        print(-1)
else:
    print(1)
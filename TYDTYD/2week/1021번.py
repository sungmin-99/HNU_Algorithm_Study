from collections import deque
n,m=map(int,input().split())
answer=0
k=0

q=list(map(int,input().split()))

a=deque([i+1 for i in range(n)])

while(len(q)-1>=k): 
    if a[0]==q[k]:
        a.popleft()
        k=k+1
    elif a.index(q[k])-a.index(a[0])<len(a)-a.index(q[k])+a.index(a[0]):
        for j in range(a.index(q[k])-a.index(a[0])):
            a.append(a[0])
            a.popleft()
            answer=answer+1
    else:
        for j in range(len(a)-a.index(q[k])+a.index(a[0])):
            a.appendleft(a[len(a)-1])
            a.pop()
            answer=answer+1

print(answer,a)
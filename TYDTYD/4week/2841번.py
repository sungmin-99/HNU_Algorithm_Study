from collections import deque

n,p=map(int,input().split())
count=deque()
index=0

for i in range(n):
    count.append([])

for i in range(n):
    x,y=map(int,input().split())
    if len(count[x-1])==0:
        count[x-1].append(y)
        index=index+1
    elif y>max(count[x-1]):
        count[x-1].append(y)
        index=index+1
    elif y==max(count[x-1]):
        pass
    elif y<min(count[x-1]):
        index=index+len(count[x-1])+1
        del count[x-1][:]
        count[x-1].append(y)
    else:
        a=len(count[x-1])
        while(a>0):
            a=a-1
            if y>count[x-1][a]:
                index=index+len(count[x-1])-(a+1)+1
                del count[x-1][a+1:]
                count[x-1].append(y)
                a=-1
            elif y==count[x-1][a]:
                index=index+len(count[x-1])-(a+1)
                del count[x-1][a+1:]
                a=-1
                
print(index)
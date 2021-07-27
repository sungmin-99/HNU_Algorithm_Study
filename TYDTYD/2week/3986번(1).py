import sys
from collections import deque

n=int(input())
test=deque([])
index=0
answer=0

for j in range(n):
    index=input()
    test.clear()
    for z in range(len(index)):
        test.append(index[z])
    t=0
    if len(test)%2==0:
        while(t>=0):
            if len(test)<=0 or t>=len(test)-1:
                t=-1
            elif test[t]==test[t+1]:
                del test[t]
                del test[t]
                t=0
            else:
                t=t+1
        if len(test)==0:
            answer=answer+1

print(answer)
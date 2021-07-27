n=int(input())
test=[]
counta=0
countb=0
index=0

for k in range(n):
    test.append([i for i in input()])


for j in range(len(test)):
    t=0
    counta=0
    countb=0
    if len(test[j])%2==0:
        if len(test[j])==2 and test[j][t]!=test[j][t+1]:
            t=1000000000
        for m in range(len(test[j])):
            if test[j][m]=='A':
                counta=counta+1
                if m!=0 and test[j][m]==test[j][m-1]:
                    counta=0
                elif counta==2 and countb%2!=0:
                    t=1000000000
                elif counta==2:
                    counta=0
            elif test[j][m]=='B':
                countb=countb+1
                if m!=0 and test[j][m]==test[j][m-1]:
                    countb=0
                elif countb==2 and counta%2!=0:
                    t=1000000000
                elif countb==2:
                    counta=0
        if counta==0 and countb==0 and t!=1000000000:
            index=index+1
                
print(index)
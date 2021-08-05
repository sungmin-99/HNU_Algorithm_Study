N=int(input())
c=[]

for i in range(N):
    c.append(input())
    if c[i]=='KBS1':
        index1=i
    elif c[i]=='KBS2':
        index2=i

if index2==1 and index1==2:
    print(3)
elif index1<index2:
    print('1'*index1+'4'*index1+'1'*index2+'4'*(index2-1))
elif index1>index2:
    print('1'*index2+'4'*index2+'1'*index1+'4'*index1)

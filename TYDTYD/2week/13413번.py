T=int(input())
answer=[0 for l in range(T)]

for i in range(T):
    n=int(input())
    cntw=0
    cntb=0
    a=input()
    b=input()
    if a.count('W')==b.count('W'):
        for j in range(n):
            if a[j]!=b[j]:
                answer[i]=answer[i]+1
        answer[i]=answer[i]//2
    else:
        for m in range(n):
            if a[m]!=b[m] and a[m]=='W':
                cntw=cntw+1
            elif a[m]!=b[m] and a[m]=='B':
                cntb=cntb+1
        if cntw>=cntb:
            answer[i]=cntw
        else:
            answer[i]=cntb

for k in range(T):
    print(answer[k])
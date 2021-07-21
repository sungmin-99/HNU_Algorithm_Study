a=int(input())
b=[]
result=[]
index=[]
answer=0

for i in range(a):
    b.append(input().split())

for l in range(a):
    for j in range(5):
        for k in range(a):
            if b[l][j]==b[k][j] and l!=k:
                index.append(k)
    index1=list(set(index))
    result.append(len(index1))
    index1=[]
    index=[]

print(result.index(max(result[:]))+1)

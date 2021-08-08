n,k,l=map(int,input().split())
index=0

while(n>0):
    n=n-1
    index=index+1
    if k==l-1 and k%2==1 or k==l+1 and k%2==0:
        n=-1
    if k%2==0 and l%2==0:
        k=k//2
        l=l//2
    elif k%2==0 and l%2==1:
        k=k//2
        l=l//2+1
    elif k%2==1 and l%2==0:
        k=k//2+1
        l=l//2
    else:
        k=k//2+1
        l=l//2+1
    
print(index)
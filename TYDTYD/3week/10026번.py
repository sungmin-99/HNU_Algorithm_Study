import sys
sys.setrecursionlimit(100000)

def dfsR(x,y):
    if x>=n or x<=-1 or y>=n or y<=-1:
        return False
    if color[x][y]=='R':
        color[x][y]=1
        dfsR(x-1,y)
        dfsR(x+1,y)
        dfsR(x,y-1)
        dfsR(x,y+1)
        return True
    return False

def dfsG(x,y):
    if x>=n or x<=-1 or y>=n or y<=-1:
        return False
    if color[x][y]=='G':
        color[x][y]=1
        dfsG(x-1,y)
        dfsG(x+1,y)
        dfsG(x,y-1)
        dfsG(x,y+1)
        return True
    return False

def dfsB(x,y):
    if x>=n or x<=-1 or y>=n or y<=-1:
        return False
    if color[x][y]=='B':
        color[x][y]=2
        dfsB(x-1,y)
        dfsB(x+1,y)
        dfsB(x,y-1)
        dfsB(x,y+1)
        return True
    return False

def dfsRG(x,y):
    if x>=n or x<=-1 or y>=n or y<=-1:
        return False
    if color[x][y]==1:
        color[x][y]=0
        dfsRG(x-1,y)
        dfsRG(x+1,y)
        dfsRG(x,y-1)
        dfsRG(x,y+1)
        return True
    return False

def dfsBB(x,y):
    if x>=n or x<=-1 or y>=n or y<=-1:
        return False
    if color[x][y]==2:
        color[x][y]=0
        dfsBB(x-1,y)
        dfsBB(x+1,y)
        dfsBB(x,y-1)
        dfsBB(x,y+1)
        return True
    return False


n=int(input())
color=[]
answer1,answer2=0,0

for i in range(n):
    color.append(list(input()))

for i in range(n):
    for j in range(n):
        if dfsR(i,j)==True:
            answer1=answer1+1
        elif dfsG(i,j)==True:
            answer1=answer1+1
        elif dfsB(i,j)==True:
            answer1=answer1+1

for i in range(n):
    for j in range(n):
        if dfsRG(i,j)==True:
            answer2=answer2+1
        elif dfsBB(i,j)==True:
            answer2=answer2+1

print(answer1,answer2)
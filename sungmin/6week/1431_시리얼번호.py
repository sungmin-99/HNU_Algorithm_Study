n = int(input())

def sumNum(x):
    ans = 0
    for i in x:
        if i.isdigit():
            ans += int(i)
    return ans

arr = []
for i in range(n):
    a = input()
    arr.append(a)

arr.sort(key = lambda x:(len(x), sumNum(x), x))
for i in arr:
    print(i)
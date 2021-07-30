n = int(input())
trees = list(map(int, input().split()))
grow = list(map(int, input().split()))

ans = sum(trees)
grow.sort()
for i in range(n):
    ans += i * grow[i]
print(ans)
# 1. 동전
> 정답 코드
```python
n, k = map(int, input().split())
coins = []
for _ in range(n):
    coins.append(int(input()))
coins.sort()
dp = [0] * (k + 1)
dp[0] = 1

for coin in coins:
    for i in range(coin, k + 1):
        if i - coin >= 0:
            dp[i] += dp[i - coin]

print(dp[k])
```

<br>
<b>다이나믹 프로그래밍 문제</b>
<br> dp[i - coin]에서 구했던 경우의 수를 dp[i]에 더해주는 동적 할당
<br><br><br><br><br><br>
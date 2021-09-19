# 1. 카드 구매하기
> 1차 시기
```python
n = int(input())
cards = list(map(int, input().split()))
value = 0
dp = [0] * (n + 1)

for i in range(len(cards)):
    card = i + 1
    if value <= cards[i] / card:
        value = cards[i] / card
        for j in range(card, n + 1):
            dp[j] = max(dp[j - card] + cards[i], dp[j])

print(dp[n])
```

<br>
<b>다이나믹 프로그래밍</b>
<br>각 카드의 마다 value 값을 설정하여 value가 높으면 dp를 초기화하고 낮으면 건너 띄는 알고리즘을 구성했다.
<br>한시간 동안 맞왜틀 하다가 value를 설정할 필요가 없다는 것을 깨달았다.
<br>크고 작은건 어짜피 컴퓨터가 계산해 주는것을...
<br><br><br>

> 정답
```python
n = int(input())
cards = list(map(int, input().split()))
dp = [0] * (n + 1)

for i in range(len(cards)):
    card = i + 1
    for j in range(card, n + 1):
        dp[j] = max(dp[j - card] + cards[i], dp[j])

print(dp[n])
```

<br>
<b>다이나믹 프로그래밍</b>
<br>코드를 수정할것도 없이 value만 삭제하니 귀신같이 맞았습니다가 나왔다...
<br><br><br><br><br><br>
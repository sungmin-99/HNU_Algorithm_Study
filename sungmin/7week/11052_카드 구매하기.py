n = int(input())
cards = list(map(int, input().split()))
dp = [0] * (n + 1)

for i in range(len(cards)):
    card = i + 1
    for j in range(card, n + 1):
        dp[j] = max(dp[j - card] + cards[i], dp[j])

print(dp[n])
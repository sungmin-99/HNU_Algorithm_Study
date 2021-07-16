from itertools import combinations

word = input()
n = int(input())
price = []
book = []
for _ in range(n):
    a, b = input().split()
    price.append(int(a))
    book.append(b)

wordbit = [0] * 26
for i in word:
    wordbit[ord(i) % 65] += 1

ans = 10 ** 10
for i in range(1, n + 1):
    com = list(combinations(book, i))
    for j in com:
        bit = [0] * 26
        for k in j:
            for l in k:
                bit[ord(l) % 65] += 1
        check = 0
        for k in range(26):
            if wordbit[k] > bit[k]:
                check = 1
        if check == 0:
            for k in j:
                check += price[book.index(k)]
        else:
            continue
        if ans > check:
            ans = check
if ans == 10 ** 10:
    print("-1")
else:
    print(ans)
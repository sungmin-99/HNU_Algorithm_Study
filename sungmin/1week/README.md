# 1. 수리공 항승
> 1차시도
```python
n, l = map(int, input().split())
leak = list(map(int, input().split()))

check = leak[0]
cnt = 0
for i in range(1, n):
    if leak[i] - check > l - 1:
        check = leak[i]
        cnt += 1
if check == leak[-1]:
    cnt += 1
    
print(cnt)
```
<br>
아이디어 : 물이 새는 곳의 길이를 비교해서 테이프의 길이보다 길다면 테이프를 추가하는 식으로 카운트함
<br><br>
<b>틀린 이유 : 물을 막을 때, 적어도 그 위치의 좌우 0.5만큼 간격을 줘야 된다는 조건이 있는데 충족하지 않는 것으로 예상</b>
<br><br>

> 정답 코드
```python
n, l = map(int,input().split())
leak = list(map(int,input().split()))
leak.sort()

cnt = 1
start = leak[0]
end = start + l - 0.5
for i in leak:
    if end >= i:
        continue
    else:
        cnt += 1
        end = i + l - 0.5

print(cnt)
```
<br>
아이디어 : 테이프의 길이를 정해서 물이 새는 곳의 위치가 테이프의 end 보다 크다면 테이프의 갯수를 카운트함
<br><br>

#2. 전공책

> 1차시도
```python
from itertools import combinations
from itertools import permutations

word = input()
n = int(input())
price = []
book = []
for _ in range(n):
    a, b = input().split()
    price.append(int(a))
    book.append(b)

ans = 10 ** 10
for i in range(1, n + 1):
    com = list(combinations(book, i))
    for j in com:
        newWord = ''
        for k in j:
            newWord = newWord + k
        # print(newWord)
        if word in list(permutations(newWord, len(word))):
            print(word)
```
<br>
아이디어 : 각 책마다 word의 길이에 받는 모든 조합을 뽑아내 브루트 포스로 비교
<br><br>
<b>틀린 이유 : 시간 복잡도가 너무 비효율적이라 테스트케이스 조차도 제대로 동작하지 않음</b>
<br><br>
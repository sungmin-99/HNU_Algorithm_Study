# 1. 좋은 단어
> 1차시도
```python
n = int(input())
words = []
for _ in range(n):
    words.append(input())

cnt = 0
for i in range(n):
    stack = []
    check = True
    for j in words[i]:
        if stack == []:
            stack.append(j)
        elif j == 'A' and stack[-1] == 'A':
            stack.pop()
        elif j == 'B' and stack[-1] == 'B':
            stack.pop()
        elif len(stack) == 1:
            stack.append(j)
        else:
            check = False
            break
    if stack != []:
        check = False
    if check:
        cnt += 1
print(cnt)
```
<br>
<b>틀린이유 : 조건을 빼먹은 것 같은데 뭘 빼먹었는지 잘 모르겠다...</b>
<br><br><br><br><br><br>

> 정답 코드
```python
n = int(input())
words = []
for _ in range(n):
    words.append(input())

cnt = 0
for i in range(n):
    stack = []
    check = True
    for j in words[i]:
        if stack == []:
            stack.append(j)
        elif stack[-1] == j:
            stack.pop()
        else:
            stack.append(j)
    if not(stack):
        cnt += 1
print(cnt)
```

<br>
<b>빼먹은 조건을 찾을 수 없어서 단어의 문자와 스택의 문자가 같으면 pop하고 다르면 push하여 마지막에 스택이 비어있으면 True이고 스택이 비어 있지 않다면 False 이다.</b>
<br><br><br><br><br><br>


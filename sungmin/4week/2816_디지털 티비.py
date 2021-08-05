n = int(input())
arr = []
for i in range(n):
    channel = input()
    if channel == 'KBS1':
        num1 = i
    elif channel == 'KBS2':
        num2 = i
    arr.append(channel)

ans = ''
ans += '1' * num1
ans += '4' * num1
if num1 > num2:
    num2 += 1
ans += '1' * num2
ans += '4' * (num2 - 1)
print(ans)
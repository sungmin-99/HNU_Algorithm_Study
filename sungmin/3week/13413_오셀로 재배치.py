t = int(input())
for _ in range(t):
    n = int(input())
    bw1 = input()
    bw2 = input()
    cnt = 0
    b = 0
    w = 0
    for i in range(n):
        if bw1[i] != bw2[i]:
            if bw1[i] == 'B':
                b += 1
                cnt += 1
            else:
                w += 1
                cnt += 1
    print(cnt - min(b, w))
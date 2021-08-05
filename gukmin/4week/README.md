디지털티비
=============
    n = int(input())
    ch = []

    for _ in range(n):
        ch.append(input())

    a = ch.index('KBS1')
    A = a*'1'+a*'4'
    ch.pop(a)
    ch.insert(0,'KBS1')
    print(ch)
    b = ch.index('KBS2')
    B = b*'1'+ b*'4'
    print(ch)
    print(A+B)
    
등수구하기    
=============
    n, l, p = map(int, input().split())
    if n == 0:
        print(1)
    else:
        score = list(map(int, input().split()))
        score.append(l)
        score.sort(reverse=True)
        r = score.index(l) + 1
        if r > p or n==p and l == score[-1]:
            print(-1)

        else:
            print(r)

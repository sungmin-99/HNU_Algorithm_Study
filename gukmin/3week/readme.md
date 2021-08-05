좋은단어
=============
    from collections import deque
    n = int(input()) 
    deq = deque()
    list = []
    cnt = 0
    for _ in range(n):
        list.append(input())
    for i in list:
        deq.clear()
        for j in i:
            deq.append(j)
            if len(deq) > 1:
                if deq[-1] == deq[-2]:
                    deq.pop()
                    deq.pop()
        if len(deq) == 0:
            cnt += 1

    print(cnt)


회전하는 큐
=============
    from collections import deque
    deq = deque()
    n, m = map(int, input().split())
    ls = list(map(int, input().split()))
    js = [0]*n
    cnt = 0
    for i in range(m):
        js[ls[i]-1] = ls[i]
    for j in js:
        deq.append(j)


    for k in ls:
        while 1:
            if deq.index(k) == 0:
                deq.popleft()
                break
            elif deq.index(k)-0 <= len(deq)-deq.index(k):
                popop = deq.popleft()
                deq.append(popop)
                cnt += 1
            else:
                popop = deq.pop()
                deq.appendleft(popop)
                cnt += 1
    print(cnt)

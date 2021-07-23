상자의 균형 1차 시도
=============
    n, l = map(int, input().split())
    mid = list(map(int,input().split()))
    mid.reverse()

    ct = 0
    for i in range(n-1):
        if sum(mid[0:i+1])/(i+1) >= mid[i+1]+l or sum(mid[0:i+1])/(i+1) <= mid[i+1]-l:
            ct += 1

    if ct == 0:
        print("stable")
    else:
        print("unstable")
###### 상자의 무게중심을 리스트로 받고 리스트를 거꾸로 만들어줌 
###### 채점 해보니까 시간초과 떠서 O를 줄일 방법을 생각해봄 
        
        
상자의 균형 2차 시도
=============
    import sys

    n, l = map(int, input().split())
    mid = list(map(int,input().split()))
    mid.reverse()

    total = 0
    for i in range(n-1):
        total += mid[i]
        avg = total / (i + 1)
        if avg >= mid[i+1]+l or avg <= mid[i+1]-l:
            print("unstable")
            sys.exit()

    print("stable")
    
###### 시간을 줄이기 위해 total과 avg를 써서 누적시켜서 더해줌 
###### 그리고 위에서 cnt가 한번이라도 1이 되면 상자가 불안정 상태이기 때문에 바로 끝내줌 sys.exit 사용함


###### 배운점
###### sys.exit를 배웠다 적절히 내장함수를 사용하자 필요한 기능이 있는지 인터넷에 검색 해보자
###### 시간줄이는것은 매우 중요하다.




임시반장 정하기
=============

    n = int(input())
    stu = [list(map(int,input().split())) for _ in range(n)]
    kk = []


    for i in range(n):
        total = 0
        for j in range(5):
            for k in range(n):
                if stu[i][j] == stu[k][j]:
                    total += 1
        kk.append(total)



    print(kk.index(max(kk))+1)
    
   ###### 중복문제 해결 못해서 틀림 

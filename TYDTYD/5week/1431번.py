import sys
input=sys.stdin.readline

n=int(input())
s=[]
p=[0]*n

for i in range(n): # 시리얼 넘버 입력 및 리스트 생성
    serial=input()
    s.append(serial)

result1=[]

for i in range(len(s)):
    result1.append(len(s[i])) # 문자열 길이 저장
    for j in range(len(s[i])): 
        if ord(s[i][j])>=48 and ord(s[i][j])<=57: # 숫자일 경우 숫자 저장
            p[i]=p[i]+int(s[i][j]) # 숫자 합 계산

result2=[]

for i in range(n): # 각각에 대한 정렬 기준 저장
    result2.append((result1[i],p[i],s[i]))

result2.sort(key=lambda x:(x[0],x[1],x[2])) # 정렬 기준대로 정렬

for i in range(len(result2)): # 출력
    print(result2[i][2],end='')
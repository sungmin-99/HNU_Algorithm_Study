dp = [1, 0, 0, 0, 0, 0, 0, 0]

def walk(x):
    tmp = [0 for _ in range(8)]
    tmp[0] = x[1] + x[3]
    tmp[1] = x[0] + x[2] + x[3]
    tmp[2] = x[1] + x[3] + x[4] + x[5]
    tmp[3] = x[0] + x[1] + x[2] + x[5]
    tmp[4] = x[2] + x[5] + x[6]
    tmp[5] = x[3] + x[2] + x[4] + x[7]
    tmp[6] = x[4] + x[7]
    tmp[7] = x[5] + x[6]

    for i in range(8):
        tmp[i] = tmp[i] % 1000000007
    return tmp

for i in range(int(input())):
    dp = walk(dp)

print(dp[0])
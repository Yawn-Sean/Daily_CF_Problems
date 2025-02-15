# 参考 https://github.com/Yawn-Sean/Daily_CF_Problems/blob/main/daily_problems/2025/01/0127/solution/cf167b.md
def main1():
    n,l,k = map(int, input().split())
    p = list(map(lambda x: int(x) / 100 , input().split()))
    a = list(map(lambda x: int(x), input().split()))
    k = min(k, 200)
    dp = [[0] * (201) for _ in range(n + 1)] 
    cdp = [[0] * (201) for _ in range(n + 1)]
    dp[0][k] = 1
    for i in range(n):
        if a[i] >= 0:
            for j in range(n + 1):
                for c in range(201):
                    if dp[j][c]:
                        cdp[j + 1][min(200, c + a[i])] += dp[j][c] * p[i]
                        cdp[j][c] += dp[j][c] * (1 - p[i])
            for j in range(n + 1):
                for c in range(201):
                    dp[j][c] = cdp[j][c]
                    cdp[j][c] = 0
    for i in range(n):
        if a[i] < 0:
            for j in range(n + 1):
                for c in range(201):
                    if dp[j][c]:
                        cdp[j][c] += dp[j][c] * (1 - p[i])
                        if c:
                            cdp[j+1][c - 1] += dp[j][c] * p[i]
            for j in range(n + 1):
                for c in range(201):
                    dp[j][c] = cdp[j][c]
                    cdp[j][c] = 0     
    ans = 0
    
    for j in range(n + 1):
        for c in range(201):
            if j >= l:
               ans += dp[j][c]
    print(ans)

# 将奖品看做容量为0的包，将包看做奖品
def main2():
    n,l,k = map(int, input().split())
    p = list(map(lambda x: int(x) / 100 , input().split()))
    a = list(map(lambda x: int(x) + 1, input().split())) # 预处理， 全部+1
    # dp [i][j][c] 表示前i个比赛，获胜j次，背包容量为c的概率
    dp = [[[0] * (201) for _ in range(n + 1)]  for _ in range(n + 1)]
    dp[0][0][k] = 1
    for i in range(n):
        for j in range(i + 1):
            for c in range(201):
                if dp[i][j][c]:
                    dp[i + 1][j][c] += dp[i][j][c] * (1 - p[i])
                    dp[i + 1][j + 1][min(200, c + a[i])] += dp[i][j][c] * p[i]
    ans = 0
    for j in range(l, n + 1):
        for c in range(201):
            if c >= j: # 容量必须大于等于获胜的次数才行
                ans += dp[n][j][c]
    print(ans)


main2()
                


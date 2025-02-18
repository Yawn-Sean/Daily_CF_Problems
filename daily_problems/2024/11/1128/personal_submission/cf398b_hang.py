# 题解：https://github.com/Yawn-Sean/Daily_CF_Problems/blob/main/daily_problems/2024/11/1128/solution/cf398b.md
def main():
    n,m = map(int, input().split())
    r = [0]*n
    c = [0]*n
    for i in range(m):
        x,y = map(lambda x: int(x)-1, input().split())
        r[x] = 1
        c[y] = 1
    
    v1 = n - sum(r)
    v2 = n - sum(c)
    dp = [[0] * (v2 + 2) for _ in range(v1 + 2)]
    for i in range(v1, -1, -1):
        for j in range(v2, -1, -1):
            if i == v1 and j == v2: continue
            dp[i][j] = (n * n + (v1 - i) * (v2 - j) * dp[i + 1][j + 1]+ (v1 - i) * (n - v2 + j) * dp[i + 1][j] + (n - v1 + i) * (v2 - j) * dp[i][j + 1]) / (n * n - (n - v1 + i) * (n - v2 + j))
    
    print(dp[0][0])

main()
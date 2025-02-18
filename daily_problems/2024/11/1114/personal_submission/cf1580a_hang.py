#题解：https://github.com/Yawn-Sean/Daily_CF_Problems/blob/main/daily_problems/2024/11/1114/solution/cf1580a.md
def main():
    n,m = map(int,input().split())
    g = [[int(x) for x in input()] for _ in range(n)]    
    res = n * m
    cnt = [0] * m
    calc = [0] * m
    for i in range(n - 4):
        for j in range(m):
            cnt[j] = 0
        for j in range(i + 1, i + 4):
            for k in range(m):
                cnt[k] += g[j][k]
        for j in range(i + 4, n):
            for k in range(m):
                calc[k] = cnt[k]  
            for k in range(1, m - 1):
                calc[k] += 2 - g[i][k] - g[j][k]
            for k in range(1, m):
                calc[k] += calc[k - 1]
            cur = n * m
            for k in range(m - 1, 2, -1):
                cur = min(cur, calc[k - 1] + j - i - 1 - cnt[k])
                res = min(res, cur - calc[k - 3] + j - i - 1 - cnt[k - 3])
            
            for k in range(m):
                cnt[k] += g[j][k]
    print(res)
t = int(input())
for _ in range(t):
    main()
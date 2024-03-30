INF = 10**9 
def main():
    n = int(input())
    a = list(map(int, input().split()))
    a = [a[i] - 1 for i in range(n)]
    z = [[] for _ in range(8)]
    for i in range(n):
        z[a[i]].append(i)
    def solve(en):
        cur = [0] * 8
        dp = [[-INF for _ in range(256)] for _ in range(n + 1)]
        dp[0][0] = 0
        for i in range(n):
            for j in range(256):
                if dp[i][j] == -INF:
                    continue
                for k in range(8):
                    if j & (1 << k):
                        continue
                    it = cur[k] + en - 1
                    if it >= len(z[k]):
                        continue
                    dp[z[k][it] + 1][j | (1 << k)] = max(dp[z[k][it] + 1][j | (1 << k)], dp[i][j])
                    it += 1
                    if it >= len(z[k]):
                        continue
                    dp[z[k][it] + 1][j | (1 << k)] = max(dp[z[k][it] + 1][j | (1 << k)], dp[i][j] + 1)
            cur[a[i]]+= 1
        res = -INF
        for i in range(n + 1):
            res = max(res, dp[i][-1])
        if res == -INF:
            return -1
        return res * (en + 1) + (8- res) * en
    
    ans = -1
    l = 1
    r = n // 8  + 1
    while r - l > 1:
        m = (l + r) >> 1
        if solve(m) != -1:
            l = m
        else:
            r = m
    ans = max(solve(l), solve(r))
    if ans == -1:
        ans = 0
        for i in range(8):
            if (len(z[i]) != 0):
                ans +=1
    print(ans)


main()

# Submission link: https://codeforces.com/contest/1875/submission/309281701
def main():
    t = II()
    outs = []

    inf = 10 ** 8

    for _ in range(t):
        n = II()
        nums = LII()
        cnt = [0] * (n + 1)
        
        for v in nums:
            if v < n:
                cnt[v] += 1
        
        dp = [inf] * (n + 1)
        dp[n] = 0
        
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n + 1):
                dp[i] = fmin(dp[i], dp[j] + j * cnt[i])
        
        ans = dp[0]
        for i in range(n + 1):
            if cnt[i] == 0:
                ans -= i
                break
        
        outs.append(ans)

    print('\n'.join(map(str, outs)))
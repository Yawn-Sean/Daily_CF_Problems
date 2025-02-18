# Submission link: https://codeforces.com/contest/417/submission/285748370
def main():
    n, m, b = MII()

    costs = []
    monitors = []
    msks = []

    for _ in range(n):
        x, k, l = MII()
        costs.append(x)
        monitors.append(k)
        
        msk = 0
        for idx in GMI():
            msk |= 1 << idx

        msks.append(msk)

    inf = 2 * 10 ** 18

    dp = [inf] * (1 << m)
    dp[0] = 0
    ans = inf

    for i in sorted(range(n), key=lambda x: monitors[x]):
        
        cost, msk = costs[i], msks[i]
        
        for j in range(1 << m):
            nj = j | msk
            if dp[j] + cost < dp[nj]:
                dp[nj] = dp[j] + cost

        if dp[-1] + monitors[i] * b < ans:
            ans = dp[-1] + monitors[i] * b

    print(ans if ans < inf else -1)
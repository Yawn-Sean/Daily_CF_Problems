# Submission link: https://codeforces.com/contest/425/submission/319000707
def main():
    n, m, s, e = MII()
    nums1 = LII()
    nums2 = LII()

    pos = [[] for _ in range(100001)]

    for i in range(m):
        pos[nums2[i]].append(i)

    inf = 10 ** 6
    dp = [0] * (n + 1)
    ndp = [inf] * (n + 1)

    ans = 0

    for op in range(1, s // e + 1):
        cur = inf
        
        for i in range(1, n + 1):
            cur = fmin(cur, dp[i - 1])
            if cur < inf:
                if dp[i] > cur:
                    ndp[i] = dp[i]
                else:
                    p = bisect.bisect_left(pos[nums1[i - 1]], cur)
                    if p < len(pos[nums1[i - 1]]):
                        ndp[i] = pos[nums1[i - 1]][p] + 1
        
        for i in range(n + 1):
            dp[i] = ndp[i]
            ndp[i] = inf
        
        for i in range(1, n + 1):
            if dp[i] < inf and op * e + i + dp[i] <= s:
                ans = op

    print(ans)
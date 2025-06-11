# Submission link: https://codeforces.com/contest/542/submission/296223874
def main():
    n, T = MII()
    items = [[] for _ in range(T)]

    for _ in range(n):
        t, q = MII()
        items[T - t].append(q)

    inf = 10 ** 9

    dp = [-inf] * (n + 1)
    dp[0] = 0
    dp[1] = 0

    ndp = [-inf] * (n + 1)

    for i in range(T):
        items[i].sort(reverse=True)
        l = len(items[i])
        
        for j in range(n + 1):
            cur = 0
            for k in range(l + 1):
                if k > j: break
                nj = fmin(n, 2 * (j - k))
                ndp[nj] = fmax(ndp[nj], dp[j] + cur)
                if k < l:
                    cur += items[i][k]

        for j in range(n + 1):
            dp[j] = ndp[j]
            ndp[j] = -inf

    print(max(dp))
def main():
    n = II()
    res = LII()
    cnt = Counter(res)
    mex = 0
    for i in count(0):
        if i not in cnt:
            mex = i
            break
    if mex == 0:
        return 0
    dp = [inf] * mex
    dp[0] = cnt[0] - 1
    for i in range(1, mex):
        tmp = (i + 1) * (cnt[0] - 1)
        for j in range(1, i + 1):
            tmp = min(tmp, dp[j - 1] + (i + 1) * (cnt[j] - 1) + j)
        dp[i] = tmp

    return dp[mex - 1]


T = II()
for ii in range(T):
    print(main())

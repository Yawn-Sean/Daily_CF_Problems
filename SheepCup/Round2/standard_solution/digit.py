def main():
    n, digit = MII()
    s = I()

    mod = 10 ** 9 + 7
    val = [0] * n
    for i in range(len(s)):
        val[i + n - len(s)] = int(s[i])

    dp = [[0] * (n + 1) for _ in range(2)]
    ndp = [[0] * (n + 1) for _ in range(2)]

    dp[0][0] = 1
    dp[1][1] = 1

    for c in val:
        for i in range(2):
            for j in range(n + 1):
                for k in range(2):
                    v = k + (k ^ c) + i
                    oi = 1 if v >= 2 else 0
                    oj = j - (v & 1)
                    
                    if oj >= 0:
                        ndp[i][j] += dp[oi][oj]
                        if ndp[i][j] >= mod:
                            ndp[i][j] -= mod
        
        for i in range(2):
            for j in range(n + 1):
                dp[i][j] = ndp[i][j]
                ndp[i][j] = 0

    print(dp[0][digit] * (mod + 1) // 2 % mod if s != '0' else dp[0][digit])
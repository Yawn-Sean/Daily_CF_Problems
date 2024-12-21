# Submission link: https://codeforces.com/contest/507/submission/297584983
def main():
    n, k, mod = MII()

    dp = [[0] * k for _ in range(2)]
    ndp = [[0] * k for _ in range(2)]
    cur = 1

    for i in range(n):
        for j in range(2):
            for a in range(k):
                for b in range(10):
                    if i == n - 1 and b == 0: continue
                    na = (a + b * cur) % k
                    nj = j | (na == 0)
                    ndp[nj][na] += dp[j][a]
                    if ndp[nj][na] >= mod:
                        ndp[nj][na] -= mod
        
        for b in range(1, 10):
            na = b * cur % k
            nj = (na == 0)
            ndp[nj][na] += 1
            if ndp[nj][na] >= mod:
                ndp[nj][na] -= mod
        
        for j in range(2):
            for a in range(k):
                dp[j][a] = ndp[j][a]
                ndp[j][a] = 0
        
        cur = cur * 10 % k

    print(sum(dp[1]) % mod)
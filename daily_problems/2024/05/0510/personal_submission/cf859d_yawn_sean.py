# Submission link: https://codeforces.com/contest/859/submission/260189505
def main():
    n = II()
    grid = [LII() for _ in range(1 << n)]

    prob = [1] * (1 << n)
    dp = [0] * (1 << n)

    for i in range(n):
        nprob = [0] * (1 << n)
        ndp = [0] * (1 << n)
        
        for j in range(0, 1 << n, 1 << i + 1):
            for k in range(j, j + (1 << i)):
                for nk in range(j + (1 << i), j + (1 << i + 1)):
                    nprob[k] += prob[k] * prob[nk] * grid[k][nk] / 100
                    nprob[nk] += prob[k] * prob[nk] * grid[nk][k] / 100
                    ndp[k] = max(ndp[k], dp[nk])
                    ndp[nk] = max(ndp[nk], dp[k])

        for j in range(1 << n):
            ndp[j] += nprob[j] * (1 << i) + dp[j]
        
        prob = nprob
        dp = ndp

    print(max(dp))
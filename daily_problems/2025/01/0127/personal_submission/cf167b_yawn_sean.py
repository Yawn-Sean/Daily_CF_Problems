# Submission link: https://codeforces.com/contest/167/submission/303164778
def main():
    n, l, k = MII()
    probs = [v / 100 for v in MII()]
    vals = LII()

    dp = [[0] * 201 for _ in range(n + 1)]
    dp[0][k] = 1

    ndp = [[0] * 201 for _ in range(n + 1)]

    for idx in range(n):
        if vals[idx] >= 0:
            for i in range(n + 1):
                for j in range(201):
                    if dp[i][j]:
                        ndp[i][j] += (1 - probs[idx]) * dp[i][j]
                        ndp[i + 1][fmin(j + vals[idx], 200)] += probs[idx] * dp[i][j]
        
            for i in range(n + 1):
                for j in range(201):
                    dp[i][j] = ndp[i][j]
                    ndp[i][j] = 0

    for idx in range(n):
        if vals[idx] == -1:
            for i in range(n + 1):
                for j in range(201):
                    if dp[i][j]:
                        ndp[i][j] += (1 - probs[idx]) * dp[i][j]
                        if j: ndp[i + 1][j - 1] += probs[idx] * dp[i][j]
        
            for i in range(n + 1):
                for j in range(201):
                    dp[i][j] = ndp[i][j]
                    ndp[i][j] = 0

    print(sum(sum(x) for x in dp[l:]))
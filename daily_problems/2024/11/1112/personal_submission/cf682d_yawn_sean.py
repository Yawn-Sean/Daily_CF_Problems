# Submission link: https://codeforces.com/contest/682/submission/291124415
def main():
    n, m, k = MII()
    s1 = I()
    s2 = I()

    def f(i, j):
        return i * (m + 1) + j

    dp = [0] * ((n + 1) * (m + 1))

    for _ in range(k):
        for i in range(n):
            for j in range(m):
                if s1[i] == s2[j]:
                    dp[f(i + 1, j + 1)] = dp[f(i, j)] + 1
        
        for i in range(n):
            for j in range(m):
                dp[f(i + 1, j + 1)] = max(dp[f(i, j + 1)], dp[f(i + 1, j)], dp[f(i + 1, j + 1)])

    print(dp[f(n, m)])
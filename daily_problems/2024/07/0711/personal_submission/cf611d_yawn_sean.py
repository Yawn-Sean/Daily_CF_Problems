# Submission Link: https://codeforces.com/contest/611/submission/269805046
def main():
    n = II()
    s = I()

    def f(x, y):
        return x * n + y

    mod = 10 ** 9 + 7

    lcp = [0] * (n * n)

    for i in range(n - 1, -1, -1):
        for j in range(i + 1):
            if s[j] == s[i]:
                lcp[f(j, i)] = 1
                if i + 1 < n: lcp[f(j, i)] += lcp[f(j + 1, i + 1)]

    dp = [0] * (n * (n + 1) // 2)
    dp_acc = [0] * (n * (n + 1) // 2)

    def p(x, y):
        return x * (x + 1) // 2 + y

    for i in range(n):
        dp_acc[p(0, i)] = 1
        dp[p(i, i)] = 1

    dp_acc[p(0, 0)] = 1

    def check(i1, i2, l):
        return lcp[f(i1, i2)] < l and s[i1 + lcp[f(i1, i2)]] < s[i2 + lcp[f(i1, i2)]]

    for i in range(1, n):
        if s[i] != '0':
            for j in range(n - i):
                
                if j:
                    dp[p(i + j, j)] += dp_acc[p(i - 1, min(i, j) - 1)]
                    if dp[p(i + j, j)] >= mod:
                        dp[p(i + j, j)] -= mod
                
                if i > j and check(i - j - 1, i, j + 1):
                    dp[p(i + j, j)] += dp[p(i - 1, j)]
                    if dp[p(i + j, j)] >= mod:
                        dp[p(i + j, j)] -= mod
        
        for j in range(i + 1):
            dp_acc[p(i, j)] = dp[p(i, j)]
            if j:
                dp_acc[p(i, j)] += dp_acc[p(i, j - 1)]
                if dp_acc[p(i, j)] >= mod:
                    dp_acc[p(i, j)] -= mod

    print(dp_acc[p(n - 1, n - 1)])
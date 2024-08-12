# Submission Link: https://codeforces.com/contest/611/submission/269811190
def main():
    n = II()
    s = I()

    mod = 10 ** 9 + 7

    def p(x, y):
        return x * (x + 1) // 2 + y

    lcp = [0] * (n * (n + 1) // 2)

    for i in range(n - 1, -1, -1):
        for j in range(i + 1):
            if s[j] == s[i]:
                lcp[p(i, i - j)] = 1
                if i + 1 < n: lcp[p(i, i - j)] += lcp[p(i + 1, i - j)]

    dp = [0] * (n * (n + 1) // 2)

    for i in range(n):
        dp[p(i, i)] = 1

    def check(i1, i2, l):
        x = lcp[p(i2, i2 - i1)]
        return x < l and s[i1 + x] < s[i2 + x]

    for i in range(1, n):
        if s[i] != '0':
            cur = 0
            for j in range(n - i):
                if j:
                    dp[p(i + j, j)] += cur
                    if dp[p(i + j, j)] >= mod:
                        dp[p(i + j, j)] -= mod
                
                if i > j:
                    cur += dp[p(i - 1, j)]
                    if cur >= mod:
                        cur -= mod
                
                if i > j and check(i - j - 1, i, j + 1):
                    dp[p(i + j, j)] += dp[p(i - 1, j)]
                    if dp[p(i + j, j)] >= mod:
                        dp[p(i + j, j)] -= mod

    ans = 0
    for i in range(n):
        ans += dp[p(n - 1, i)]
        if ans >= mod:
            ans -= mod

    print(ans)
# Submission link: https://codeforces.com/contest/835/submission/262814431
def main():
    def f(x, y):
        return x * n + y

    s = I()
    n = len(s)

    dp = [0] * (n * n)
    for i in range(n):
        dp[f(i, i)] = 1

    for str_len in range(2, n + 1):
        for i in range(n + 1 - str_len):
            j = i + str_len - 1
            if s[i] == s[j] and (str_len == 2 or dp[f(i + 1, j - 1)]):
                dp[f(i, j)] = dp[f(i, i + str_len // 2 - 1)] + 1

    cnt = [0] * (n + 1)
    for i in range(n):
        for j in range(i, n):
            cnt[dp[f(i, j)]] += 1

    for i in range(n, 0, -1):
        cnt[i-1] += cnt[i]

    print(' '.join(map(str, cnt[1:])))
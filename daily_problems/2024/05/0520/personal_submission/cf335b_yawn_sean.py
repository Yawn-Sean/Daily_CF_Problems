# Submission link: https://codeforces.com/contest/335/submission/261711530
def main():
    s = I()
    cnt = Counter(s)
    c, x = cnt.most_common()[0]
    if x >= 100:
        print(c * 100)
        exit()

    n = len(s)
    dp = [0] * (n * n)

    def f(i, j):
        return i * n + j

    for i in range(n):
        dp[f(i, i)] = 1

    for substr_len in range(2, n + 1):
        for l in range(n - substr_len + 1):
            r = l + substr_len - 1
            if s[l] == s[r]:
                if r == l + 1: dp[f(l, r)] = 2
                else: dp[f(l, r)] = dp[f(l + 1, r - 1)] + 2
            else:
                dp[f(l, r)] = max(dp[f(l + 1, r)], dp[f(l, r - 1)])

    semi_palindrome = []
    l, r = 0, n - 1
    while l < r:
        if s[l] == s[r]:
            semi_palindrome.append(s[l])
            l += 1
            r -= 1
        else:
            if dp[f(l, r)] == dp[f(l + 1, r)]: l += 1
            else: r -= 1

    ans = ''.join(semi_palindrome)
    if len(ans) >= 50:
        ans = ans[:50]
        print(ans + ans[::-1])
    else:
        mid = s[l] if l == r else ''
        print(ans + mid + ans[::-1])
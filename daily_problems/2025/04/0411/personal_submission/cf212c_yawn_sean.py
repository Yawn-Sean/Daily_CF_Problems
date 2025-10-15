# Submission link: https://codeforces.com/problemset/submission/212/314945890
def main():
    s = I()
    n = len(s)

    s += s[0]

    ans = 0

    # A 作为开头
    dp0, dp1 = 1, 0

    for i in range(n):
        if s[i] == 'A':
            dp0, dp1 = dp0 + dp1, (0 if s[i + 1] == 'A' else dp1)
        else:
            dp0, dp1 = dp1, (dp0 if s[i + 1] == 'A' else dp1)

    ans += dp0

    # B 作为开头
    dp0, dp1 = 0, 1

    for i in range(n):
        if s[i] == 'A':
            dp0, dp1 = dp0 + dp1, (0 if s[i + 1] == 'A' else dp1)
        else:
            dp0, dp1 = dp1, (dp0 if s[i + 1] == 'A' else dp1)

    ans += dp1

    print(ans)
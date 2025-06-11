# Submission link: https://codeforces.com/contest/407/submission/287841618
def main():
    n = II()
    to_pos = LGMI()
    mod = 10 ** 9 + 7

    dp = [0] * (n + 1)

    for i in range(n):
        dp[i + 1] = (dp[i] * 2 - dp[to_pos[i]] + 2) % mod

    print(dp[n])
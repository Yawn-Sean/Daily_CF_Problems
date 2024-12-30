# Submission link: https://codeforces.com/contest/822/submission/276021121
def main():
    prime_factor = list(range(5 * 10 ** 6 + 1))
    for i in range(2, 5 * 10 ** 6 + 1):
        if prime_factor[i] == i:
            for j in range(i * i, 5 * 10 ** 6 + 1, i):
                if prime_factor[j] == j:
                    prime_factor[j] = i

    mod = 10 ** 9 + 7
    dp = [0] * (5 * 10 ** 6 + 1)
    for i in range(2, 5 * 10 ** 6 + 1):
        p = prime_factor[i]
        dp[i] = (dp[i // p] + i * (p - 1) // 2) % mod

    t, l, r = MII()

    ans = 0
    for i in range(r, l - 1, -1):
        ans = (ans * t + dp[i]) % mod

    print(ans)
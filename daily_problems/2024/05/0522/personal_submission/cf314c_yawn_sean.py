# Submission link: https://codeforces.com/contest/314/submission/262070789
def main():
    mod = 10 ** 9 + 7

    n = II()
    nums = LII()

    fen = FenwickTree(10 ** 6 + 1)
    dp = [0] * (10 ** 6 + 1)

    fen.add(0, 1)

    for num in nums:
        v = (fen.sum(num) * num - dp[num]) % mod
        dp[num] += v
        dp[num] %= mod
        fen.add(num, v)

    print(sum(dp) % mod)
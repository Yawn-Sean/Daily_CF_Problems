# Submission link: https://codeforces.com/contest/1561/submission/264329941
def main():
    n, mod = MII()
    prime_factors = list(range(n + 1))

    for i in range(2, n + 1):
        if prime_factors[i] == i:
            for j in range(i, n + 1, i):
                prime_factors[j] = i

    def factors(x):
        ans = [1]
        while x > 1:
            p = prime_factors[x]
            c = 0
            while x % p == 0:
                x //= p
                c += 1
            for i in range(len(ans)):
                val = ans[i]
                for _ in range(c):
                    val *= p
                    ans.append(val)
        return ans

    dp = [0] * (n + 1)
    acc_dp = [0] * (n + 1)
    dp[1] = acc_dp[1] = 1

    cur = 0
    for i in range(2, n + 1):
        dp[i] = acc_dp[i-1]
        for f in factors(i):
            if f > 1:
                cur -= dp[(i - 1) // f]
                cur += dp[i // f]
                cur %= mod
        dp[i] += cur
        dp[i] %= mod
        acc_dp[i] = acc_dp[i-1] + dp[i]
        acc_dp[i] %= mod

    print(dp[n])
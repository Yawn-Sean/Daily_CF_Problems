'''
https://codeforces.com/contest/822/submission/276040416
CF822 D
2024/8/13 Y1
1800 
Prime Factors
'''

prime_factors = []

def initPrimes():
    global prime_factors
    prime_factors = list(range(5 * 10 ** 6 + 1))
    for i in range(2, int((5 * 10 ** 6) ** 0.5) + 1):
        if prime_factors[i] == i:
            for j in range(i * i, 5 * 10 ** 6 + 1, i):
                if prime_factors[j] == j:
                    prime_factors[j] = i

if __name__ == '__main__':
    if not prime_factors:
        initPrimes()

    MOD = 10 ** 9 + 7
    dp = [0] * (5 * 10 ** 6 + 1)
    for x in range(2, 5 * 10 ** 6 + 1):
        p = prime_factors[x]
        dp[x] = (dp[x // p] + x * (p - 1) // 2) % MOD

    t, l, r = map(int, input().split())
    ans, f = 0, 1
    for x in range(l, r + 1):
        ans = (ans + f * dp[x]) % MOD
        f = f * t % MOD

    print(ans)


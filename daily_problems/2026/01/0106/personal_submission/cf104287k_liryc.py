'''
https://codeforces.com/gym/104287/submission/356587815
'''

MOD = 1000000007
fac = Factorial(1001, MOD)
b26 = pow(26, -1, MOD)
b26c = list(accumulate(range(1000), lambda x, _: x * b26 % MOD, initial=1))

def solve(s: str) -> int:
    global MOD, fac, b26c
    n, m = 0, 0
    cn = [0] * 26
    for c in s:
        if c == '?':
            m += 1
        else:
            cn[ord(c) - 97] += 1
            n += 1
    dp = [0] * (m + 1)
    dp[0] = 1
    for i in range(26):
        for j in range(m, -1, -1):
            if dp[j]:
                for k in range(1, m - j + 1):
                    dp[j + k] += dp[j] * fac.fac_inv(cn[i] + k) % MOD * fac.fac_inv(k) % MOD
                    dp[j + k] %= MOD
                dp[j] = dp[j] * fac.fac_inv(cn[i]) % MOD
    return dp[m] * fac.fac(m) % MOD * fac.fac(n + m) % MOD * b26c[m] % MOD

'''
https://codeforces.com/gym/104736/submission/363993568
'''
# counting problem
def solve(s: str, n: int) -> int:
    MOD = 10 ** 9 + 7
    n %= MOD
    cn = [0] * 26
    m = 0
    for c in s:
        x = ord(c) - 97
        m += sum(cn[x + 1:])
        cn[x] += 1
    sm = sum(cn)
    m = m * n % MOD
    c = 0
    for x in cn:
        c = (c + x * (sm - x)) % MOD
    c = c * pow(2, -1, MOD) % MOD
    c = (c * n * (n - 1) >> 1) % MOD
    return (m + c) % MOD

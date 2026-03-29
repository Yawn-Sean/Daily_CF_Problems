'''
https://codeforces.com/gym/106443/submission/368716443
'''
# probability
def solve(n: int) -> int:
    MOD = 1000000007
    b = (n - 1 >> 1) * (n - 2) % MOD if n & 1 else (n - 1) * (n - 2 >> 1) % MOD
    m = (n + 1 >> 1) - 1
    a = ((1 + m) * m >> 1) % MOD
    return a * pow(b, -1, MOD) % MOD

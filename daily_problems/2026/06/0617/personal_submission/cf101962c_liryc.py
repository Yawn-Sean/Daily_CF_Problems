'''
https://codeforces.com/gym/101962/submission/379192467
'''
def solve(n: int) -> int:
    MOD = 1000000007
    return ((n - 3) * pow(2, n, MOD) + n + 3) % MOD

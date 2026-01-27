'''
https://codeforces.com/gym/105198/submission/360078747
'''
def solve(k: int, x: int) -> int:
    MOD = 1000000007
    return x * pow(k + 1, x.bit_count() - 1, MOD) % MOD
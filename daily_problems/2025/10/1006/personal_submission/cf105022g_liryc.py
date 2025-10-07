'''
https://codeforces.com/gym/105022/submission/342139598
'''
def solve(n: int, k: int, a: list[int], b: list[int]) -> int:
    MOD = 998244353
    sum_a = sum(a) % MOD
    sum_b = sum(b) % MOD
    dp = sum(a[i] * b[i] % MOD for i in range(n)) % MOD
    return sum_a * sum_b % MOD * pow(dp, k - 1, MOD) % MOD

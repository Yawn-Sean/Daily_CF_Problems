'''
https://codeforces.com/gym/105862/submission/339039810
'''
def solve(n: int, a: list[int]) -> int:
    MOD = 1000000007
    t = 0
    for i in range(n):
        g = gcd(n, i)
        t += n // g
    iv = pow(n, -1, MOD)
    return sum(a) * t * iv * iv % MOD

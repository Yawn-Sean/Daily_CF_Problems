'''
https://codeforces.com/gym/106033/submission/352851497
'''
def solve(n: int, k: int) -> int: 
    fac = Factorial(n - 1 << 1, 998244353)
    return reduce(lambda a, x: (a + fac.comb(n - 1 << 1, x)) % 998244353, range(n - 2 - k, n + k), 0)

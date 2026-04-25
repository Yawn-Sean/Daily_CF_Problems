'''
https://codeforces.com/gym/106495/submission/372417449
math, combinations
'''
def solve(n: int) -> int:
    nodd, neven = n + 1 >> 1, n >> 1
    MOD = 1000000007
    return (comb(neven, 3) + comb(nodd, 2) * neven) % MOD

'''
https://codeforces.com/gym/105979/submission/370878466
'''
    
MOD = 998244353
fac = Factorial(1000002, MOD)

def solve(n: int, k: int) -> int: 
    return fac.combi(n + 1, k + 1)

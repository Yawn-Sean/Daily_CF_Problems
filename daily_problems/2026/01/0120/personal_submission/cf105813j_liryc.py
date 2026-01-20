'''
https://codeforces.com/gym/105813/submission/358889328
'''

MAXN = 200009
MOD = 1000000007
fac = Factorial(MAXN, MOD)

def solve(n: int, k: int, a: list[int]):
    global MAXN, MOD, fac
    return sum(a) * fac.inv(n) % MOD    

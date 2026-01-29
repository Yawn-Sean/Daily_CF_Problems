'''
https://codeforces.com/gym/105198/submission/360440952
'''
MAXN = 2000000
MOD = 1000000007
fac = Factorial(MAXN, MOD)
def solve(b: int, g: int, x: int, y: int) -> int:
    global MOD, fac    
    if x + y > g: 
        return 0
    else: 
        return (fac.combi(b + g, b) - fac.combi(b + x + y - 1, b)) % MOD

'''
https://codeforces.com/gym/104974/submission/379443368
'''
def solve(n: int, d: int) -> int:
    MOD = 998244353
    m = n >> 1
    p = m + d >> 1
    
    if m + d & 1 or p < 0 or p > m:
        return 0
        
    fac = Factorial(n, MOD)
    
    s = 0
    po2 = 1 
    for k in range(m + 1):
        t = fac.combi(m, k) * po2 % MOD * fac.fac(n - k) % MOD
        if k & 1:
            s = (s - t) % MOD
        else:
            s = (s + t) % MOD
        po2 = po2 * 2 % MOD
        
    inv = pow(pow(2, m, MOD), -1, MOD)
    return s * fac.combi(m, p) % MOD * inv % MOD

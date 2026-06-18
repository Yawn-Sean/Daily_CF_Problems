# Submission link: https://codeforces.com/gym/104974/submission/379292469
def main():
    n, d = MII()
    mod = 998244353
    
    f = Factorial(n, mod)
    pw2 = [1] * (n + 1)
    for i in range(n):
        pw2[i + 1] = pw2[i] * 2 % mod
    
    ans = 0
    
    for i in range(n // 2 + 1):
        ans += (1 if i % 2 == 0 else -1) * f.fac(n - i) * f.combi(n // 2, i) % mod * pw2[i] % mod
        ans %= mod
    
    ans = ans * pow(pw2[n // 2], -1, mod) % mod
    
    if (n // 2 - d) % 2: print(0)
    else: print(ans * f.combi(n // 2, (n // 2 + d) // 2) % mod)
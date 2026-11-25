# Submission link: https://codeforces.com/gym/106841/submission/399783206
def main(): 
    mod = 998244353
    f = Factorial(10 ** 5, mod)
    
    t = II()
    outs = []
    
    for _ in range(t):
        n, k, p = MII()
        p = p * f.inv(100) % mod
        
        ans = 0
        for i in range(k + 1):
            prob = (1 - p * (n - i) % mod * f.inv(n) % mod) % mod
            cur = f.combi(k, i) * pow(prob, n, mod) % mod
            ans += cur if (k - i) % 2 == 0 else -cur
            ans %= mod
        
        ans = ans * f.combi(n, k) % mod
        outs.append(f'{ans}')
    
    print('\n'.join(outs))
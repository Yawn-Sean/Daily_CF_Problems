# Submission link: https://codeforces.com/gym/105316/submission/351409840
def main(): 
    mod = 998244353
    M = 10 ** 5
    
    f = Factorial(M + 1, mod)
    
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        ans = 0
        
        for k in range(1, n + 1):
            ans += (n + 1) * f.inv(k + 1) % mod
            ans %= mod
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))
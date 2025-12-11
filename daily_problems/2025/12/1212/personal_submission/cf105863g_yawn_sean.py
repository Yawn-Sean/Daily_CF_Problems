# Submission link: https://codeforces.com/gym/105863/submission/352949241
def main(): 
    t = II()
    outs = []
    
    mod = 998244353
    
    for _ in range(t):
        n, k = MII()
        
        ans = n
        revk = pow(k, -1, mod)
        for i in range(1, k):
            prob = i * revk % mod
            ans += (1 - pow(prob, n, mod)) * pow(1 - prob, -1, mod)
            ans %= mod
        
        outs.append(ans * pow(k, n - 1, mod) % mod)
    
    print('\n'.join(map(str, outs)))
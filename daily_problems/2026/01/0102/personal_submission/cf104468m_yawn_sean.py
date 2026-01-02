# Submission link: https://codeforces.com/gym/104468/submission/356114533
def main(): 
    mod = 10 ** 9 + 7
    M = 2 * 10 ** 5
    f = Factorial(M, mod)
    
    t = II()
    outs = []
    
    for _ in range(t):
        n, k = MII()
        pos = [1] * (n - 1)
        
        for x in LGMI():
            pos[x] = 0
        
        ans = f.fac(n)
        
        cur = 1
        for x in pos:
            if x: cur += x
            else:
                ans = ans * f.fac_inv(cur) % mod
                cur = 1
        
        ans = ans * f.fac_inv(cur) % mod
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))
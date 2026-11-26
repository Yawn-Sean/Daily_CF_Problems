# Submission link: https://codeforces.com/gym/105846/submission/399882770
def main(): 
    mod = 998244353
    M = 10 ** 6
    f = Factorial(M, mod)
    
    ans = [0] * (M + 1)
    ans[0] = 1
    
    for i in range(1, M + 1):
        if i % 2: ans[i] = ans[i - 1] - f.fac_inv(i)
        else: ans[i] = ans[i - 1] + f.fac_inv(i)
        ans[i] %= mod
    
    for i in range(M + 1):
        ans[i] = ans[i] * f.fac(i) % mod * f.fac(i) % mod
    
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        outs.append(f'{ans[n]}' if n % 2 else '1')
    
    print('\n'.join(outs))
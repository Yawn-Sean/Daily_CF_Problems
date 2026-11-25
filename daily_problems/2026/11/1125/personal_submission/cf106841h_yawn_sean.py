# Submission link: https://codeforces.com/gym/106841/submission/399672541
def main(): 
    n = II()
    
    xs = []
    ss = []
    
    mod = 998244353
    
    for _ in range(n):
        x, s = MII()
        xs.append(x)
        ss.append(s)
    
    ans = 0
    cur = 0
    
    for i in range(n - 1, -1, -1):
        ans += (cur + ss[i]) * xs[i]
        ans %= mod
        cur = 2 * cur + ss[i]
        cur %= mod
    
    print((ans + xs[-1] + 1) % mod)
# Submission link: https://codeforces.com/gym/103114/submission/337524070
def main():
    mod = 10 ** 9 + 7
    f = Factorial(10 ** 5, mod)
    
    t = II()
    outs = []
    
    for _ in range(t):
        n, m = MII()
        
        if n == m == 1:
            outs.append(1)
        elif 2 * n <= m:
            ans = m
            # x1 + x2 + ... + xn = n - m
            ans = ans * f.combi(m - n - 1, n - 1) % mod
            ans = ans * f.fac(n - 1) % mod
            outs.append(ans)
        else:
            outs.append(0)
    
    print(*outs, sep='\n')
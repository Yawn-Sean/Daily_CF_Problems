# Submission link: https://codeforces.com/gym/105818/submission/399883151
def main(): 
    mod = 998244353
    M = 10 ** 6
    f = Factorial(M, mod)
    
    t = II()
    outs = []
    
    for _ in range(t):
        a, b, c, d = MII()
        
        if a + d - b - c not in {0, 1} or a == 1: outs.append('0')
        else:
            ans = f.combi(a + d - 2, a - 2) * f.combi(b + c, b)
            if a + d == b + c: ans *= 2
            outs.append(f'{ans % mod}')
    
    print('\n'.join(outs))
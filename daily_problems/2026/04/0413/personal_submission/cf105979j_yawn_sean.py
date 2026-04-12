# Submission link: https://codeforces.com/gym/105746/submission/370829931
def main(): 
    M = 10 ** 6 + 5
    mod = 998244353
    f = Factorial(M, mod)
    
    t = II()
    outs = []
    
    for _ in range(t):
        n, k = MII()
        outs.append(f.combi(n + 1, k + 1))
    
    print('\n'.join(map(str, outs)))
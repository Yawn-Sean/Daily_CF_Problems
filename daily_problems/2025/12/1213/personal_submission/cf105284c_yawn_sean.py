# Submission link: https://codeforces.com/gym/105284/submission/353144893
def main(): 
    M = 10 ** 6
    mod = 10 ** 9 + 7
    
    f = Factorial(M, mod)
    
    acc = [0] * (M + 1)
    
    for i in range(1, M + 1):
        acc[i] = (acc[i - 1] + f.inv(i)) % mod
    
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        outs.append((acc[n] - (1 - f.inv(n))) % mod)
    
    print('\n'.join(map(str, outs)))

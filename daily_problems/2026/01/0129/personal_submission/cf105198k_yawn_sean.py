# Submission link: https://codeforces.com/gym/105198/submission/360270802
def main(): 
    t = II()
    outs = []
    
    M = 2 * 10 ** 6
    mod = 10 ** 9 + 7
    f = Factorial(M, mod)
    
    for _ in range(t):
        b, g, x, y = MII()
        if x + y > g: outs.append(0)
        else: outs.append((f.combi(b + g, b) - f.combi(b + x + y - 1, b)) % mod)
    
    print('\n'.join(map(str, outs)))
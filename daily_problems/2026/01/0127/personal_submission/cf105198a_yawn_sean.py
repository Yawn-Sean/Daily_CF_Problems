# Submission link: https://codeforces.com/gym/105198/submission/359962060
def main(): 
    t = II()
    outs = []
    mod = 10 ** 9 + 7
    
    for _ in range(t):
        k, x = MII()
        outs.append(x * pow(k + 1, x.bit_count() - 1, mod) % mod)
    
    print('\n'.join(map(str, outs)))
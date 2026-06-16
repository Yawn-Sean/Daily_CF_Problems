# Submission link: https://codeforces.com/gym/101962/submission/379068848
def main():
    t = II()
    outs = []
    
    mod = 10 ** 9 + 7
    
    for _ in range(t):
        n = II()
        outs.append((pow(2, n, mod) * (n - 3) % mod + n + 3) % mod)
    
    print('\n'.join(map(str, outs)))
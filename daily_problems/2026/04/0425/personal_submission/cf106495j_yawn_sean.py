# Submission link: https://codeforces.com/gym/106495/submission/372313616
def main():
    t = II()
    outs = []
    mod = 10 ** 9 + 7
    
    for _ in range(t):
        n = II()
        c0 = n // 2
        c1 = (n + 1) // 2
        outs.append((math.comb(c0, 3) + math.comb(c1, 2) * c0) % mod)
    
    print('\n'.join(map(str, outs)))
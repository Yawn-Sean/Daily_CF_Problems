# Submission link: https://codeforces.com/gym/106443/submission/368674450
def main(): 
    t = II()
    mod = 10 ** 9 + 7
    
    outs = []
    
    for _ in range(t):
        n = II()
        total = (n - 1) * (n - 2) // 2 % mod
        invalid = n // 2 * (n // 2 - 1) // 2 * 3 % mod
        outs.append((total - invalid) * pow(total, -1, mod) % mod)
    
    print('\n'.join(map(str, outs)))
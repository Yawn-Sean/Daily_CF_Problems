# Submission link: https://codeforces.com/gym/105022/submission/342018133
def main():
    n, k = MII()
    v1 = LII()
    v2 = LII()
    
    mod = 998244353
    tot1 = sum(v1) % mod
    tot2 = sum(v2) % mod
    dot_val = sum(v1[i] * v2[i] % mod for i in range(n)) % mod
    
    print(tot1 * tot2 % mod * pow(dot_val, k - 1, mod) % mod)
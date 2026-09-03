# Submission link: https://codeforces.com/gym/106682/submission/389241005
def main():
    n, k, a = MII()
    mod = 998244353
    
    f = Factorial(n, mod)
    
    if n <= 2:
        if k > 0: print(0)
        else: print(pow(a, n, mod))
    else:
        print(a * a * f.combi(n - 2, k) % mod * pow(a - 1, n - 2 - k, mod) % mod)
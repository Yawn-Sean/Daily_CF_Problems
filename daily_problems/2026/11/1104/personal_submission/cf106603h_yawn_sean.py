# Submission link: https://codeforces.com/gym/106603/submission/397194135
def main(): 
    n = II()
    mod = 998244353
    
    n -= 2
    
    if n == 1: print(1)
    elif n % 3 == 0: print(pow(3, n // 3, mod))
    elif n % 3 == 2: print(2 * pow(3, n // 3, mod) % mod)
    else: print(4 * pow(3, n // 3 - 1, mod) % mod)
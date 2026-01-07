# Submission link: https://codeforces.com/gym/105390/submission/356723352
def main(): 
    M = 3 * 10 ** 5
    mod = 10 ** 9 + 7
    
    f = [0] * (M + 1)
    f[0] = 1
    
    for i in range(1, M + 1):
        f[i] = i * f[i - 1] % mod
    
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        ans = f[n // 2] * f[n - n // 2] % mod
        if n % 2 == 0: ans = ans * (n // 2 + 1) % mod
        else: ans = ans * ((n // 2 + 1) * (n // 2 + 2) // 2 % mod) % mod
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))
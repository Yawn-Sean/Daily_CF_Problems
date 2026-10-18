# Submission link: https://codeforces.com/gym/104333/submission/395088844
def main():
    n = II()
    v1 = LII()
    v2 = LII()
    
    c1 = [0] * 20
    c2 = [0] * 20
    
    for i in range(n):
        for j in range(20):
            if v1[i] >> j & 1: c1[j] += 1
            if v2[i] >> j & 1: c2[j] += 1
    
    ans = 0
    mod = 10 ** 9 + 7
    
    for i in range(20):
        ans += (c1[i] * (n - c2[i]) + c2[i] * (n - c1[i])) % mod * (1 << i) % mod
        ans %= mod
    
    for i in range(1, n):
        ans = ans * i % mod
    
    print(ans)
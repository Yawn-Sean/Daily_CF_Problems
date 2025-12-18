# Submission link: https://codeforces.com/gym/105775/submission/353921671
def main(): 
    n, m = MII()
    mod = 998244353
    
    f = Factorial(n * m, mod)
    
    ans = 0
    target = n * (m + 1) // 2
    
    for i in range(target // (m + 1) + 1):
        total = target - i * m
        ans += f.combi(total - 1, n - 1) * f.combi(n, i) % mod * (1 if i % 2 == 0 else -1) % mod
        ans %= mod
    
    print(ans)
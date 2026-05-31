# Submission link: https://codeforces.com/gym/104782/submission/376570347
def main():
    M = 5 * 10 ** 6 + 5
    mod = 10 ** 9 + 7
    
    f = Factorial(M, mod)
    
    k, s, t = MII()
    x, y = divmod(k, t)
    
    ans = 0
        
    for i in range(s + 1):
        if (s - x * i) % (x + 1) == 0:
            j = (s - x * i) // (x + 1)
            
            ans += f.combi(i - 1, t - y - 1) * f.combi(j - 1, y - 1)
            ans %= mod
    
    print(ans)
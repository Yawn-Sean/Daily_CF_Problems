# Submission link: https://codeforces.com/gym/103821/submission/381553474
def main():
    t = II()
    outs = []
    
    mod = 10 ** 9 + 7
    f = Factorial(2000, mod)
    
    for _ in range(t):
        n, k = MII()
        cols = LII()
        
        cnt = [0] * (n + 1)
        for c in cols:
            cnt[c] += 1
        
        ans = 0
        
        for i in range(1, k + 1):
            res = f.combi(k, i)
            for v in cnt:
                res = res * f.combi(v + i - 1, i - 1) % mod
            
            if (k - i) % 2: ans -= res
            else: ans += res
    
        ans %= mod
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))
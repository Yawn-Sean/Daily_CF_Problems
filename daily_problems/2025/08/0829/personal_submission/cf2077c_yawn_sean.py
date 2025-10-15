# Submission link: https://codeforces.com/contest/2077/submission/335994567
def main():
    mod = 998244353
    
    M = 2 * 10 ** 5
    pw2 = [1] * (M + 1)
    
    for i in range(1, M + 1):
        pw2[i] = 2 * pw2[i - 1] % mod
    
    t = II()
    outs = []
    
    rev4 = ((mod + 1) // 2 + mod) // 2
    
    for _ in range(t):
        n, q = MII()
        s = [int(c) for c in I()]
        c0 = s.count(0)
        c1 = s.count(1)
        
        for _ in range(q):
            idx = II() - 1
            
            if s[idx]:
                c1 -= 1
                c0 += 1
            else:
                c1 += 1
                c0 -= 1
            
            s[idx] ^= 1
            
            outs.append((c0 * (c0 + 1) // 2 + c1 * (c1 + 1) // 2 - c0 * c1 - 1) * pw2[n - 1] % mod * rev4 % mod)
    
    print('\n'.join(map(str, outs)))
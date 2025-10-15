# Submission link: https://codeforces.com/gym/105394/submission/339748503
def main():
    mod = 10 ** 9 + 7
    
    n, q, p = LI()
    n = int(n)
    q = int(q)
    p = (1 - round(float(p) * 1000000) * pow(1000000, mod - 2, mod)) % mod
    
    pows = [1] * (n + 2)
    for i in range(1, n + 2):
        pows[i] = pows[i - 1] * p % mod
    
    revp = pow(p, mod - 2, mod)
    
    rev_pows = [1] * (n + 2)
    for i in range(1, n + 2):
        rev_pows[i] = rev_pows[i - 1] * revp % mod
    
    fen_pre = FenwickTree(n + 1)
    fen_suf = FenwickTree(n + 1)
    
    outs = []
    for _ in range(q):
        query = LI()
        
        if query[0] == '+':
            x = int(query[1])
            idx = int(query[2]) - 1
    
            fen_pre.add(idx, x * pows[idx] % mod)
            fen_suf.add(idx + 1, x * rev_pows[idx] % mod)
            
        elif query[0] == '-':
            x = int(query[1])
            idx = int(query[2]) - 1
            
            fen_suf.add(idx + 1, -x * rev_pows[idx] % mod)
            fen_pre.add(idx, -x * pows[idx] % mod)
        
        else:
            idx = int(query[1]) - 1
            
            ans = 0
            ans += fen_pre.rsum(idx, n) % mod * rev_pows[idx] % mod
            ans += fen_suf.rsum(0, idx) % mod * pows[idx] % mod
            
            outs.append(ans % mod)
    
    print('\n'.join(map(str, outs)))
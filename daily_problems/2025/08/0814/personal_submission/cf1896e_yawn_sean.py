# Submission link: https://codeforces.com/contest/1896/submission/333806812
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        perm = LGMI()
        
        ans = [0] * n    
        fen = FenwickTree(2 * n)
        
        for i in range(n):
            if perm[i] >= i:
                fen.add(n + perm[i], 1)
        
        for i in range(n - 1, -1, -1):
            v = perm[i] if perm[i] >= i else perm[i] + n
            ans[perm[i]] = v - i - fen.sum(v)
            fen.add(v, 1)
    
        outs.append(' '.join(map(str, ans)))
    
    print('\n'.join(outs))
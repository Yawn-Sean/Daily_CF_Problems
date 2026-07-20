# Submission link: https://codeforces.com/gym/106627/submission/383516696
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        p = LGMI()
        
        pos = [0] * n
        
        for i in range(n):
            pos[p[i]] = i
        
        ans = pos[0]
        fen = FenwickTree(n)
        
        for i in range(1, n):
            fen.add(pos[i], 1)
        
        for i in range(1, n):
            fen.add(pos[i], -1)
            
            cur = 0
            if pos[i - 1] < pos[i]: cur = fen.rsum(pos[i - 1], pos[i])
            else: cur = fen.rsum(pos[i - 1], n - 1) + fen.rsum(0, pos[i])
            
            ans += cur % (n - i)
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))
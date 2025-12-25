# Submission link: https://codeforces.com/gym/105805/submission/355028919
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        nums = LII()
        
        fen = FenwickTree(n + 1)
        ans = 0
        diff = []
        
        for x in nums:
            v1 = fen.rsum(x + 1, n)
            v2 = fen.rsum(0, x - 1)
            
            ans += v1
            diff.append(v2 - v1)
            
            fen.add(x, 1)
    
        diff.sort()
        
        res = [ans]
        
        for x in diff:
            res.append(res[-1] + x)
        
        outs.append(' '.join(map(str, res)))
    
    print('\n'.join(outs))
# Submission link: https://codeforces.com/gym/106785/submission/396296633
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        xs = []
        ys = []
        
        for _ in range(n):
            x, y = MII()
            xs.append(x)
            ys.append(y)
        
        mnx, mxx = min(xs), max(xs)
        mny, mxy = min(ys), max(ys)
        
        def check(x, y):
            for i in range(n):
                if xs[i] == x and ys[i] == y:
                    return True
            return False
    
        if check(mnx, mny) and check(mnx, mxy) and check(mxx, mny) and check(mxx, mxy):
            outs.append('YES')
        else:
            outs.append('NO')
    
    print('\n'.join(outs))
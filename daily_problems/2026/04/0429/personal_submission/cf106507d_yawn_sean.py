# Submission link: https://codeforces.com/gym/106507/submission/372798423
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n, m = MII()
        
        ks = []
        bs = []
        
        for _ in range(n):
            k, b = MII()
            ks.append(k)
            bs.append(b)
        
        flg = True
        single = False
        x, y = 0, 0
    
        for i in range(1, n):
            if ks[i] == ks[0]:
                if bs[i] != bs[0]: flg = False
            else:
                k1, k2 = ks[0], ks[i]
                b1, b2 = bs[0], bs[i]
                single = True
                
                x = -(b2 - b1) // (k2 - k1)
                y = k1 * x + b1
        
        if single:
            for i in range(n):
                k = ks[i]
                b = bs[i]
                if y != k * x + b:
                    flg = False
        
        if m:
            nums = LII()
            
            for x0 in nums:
                if single and x0 != x:
                    flg = False
        else:
            flg = True
        
        outs.append('YES' if flg else 'NO')
    
    print('\n'.join(outs))
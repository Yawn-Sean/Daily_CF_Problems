# Submission link: https://codeforces.com/gym/101047/submission/393256087
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n, h, k = MII()
        
        xs = []
        ys = []
        
        adds = []
        minus = []
        
        for i in range(n):
            x, y = MII()
            xs.append(x)
            ys.append(y)
            
            if y >= x: adds.append(i)
            else: minus.append(i)
        
        adds.sort(key=lambda x: xs[x])
        minus.sort(key=lambda x: -ys[x])
        
        total = adds + minus
        
        dp = [-1] * (k + 1)
        dp[0] = h
        
        for i in total:
            x, y = xs[i], ys[i]
            ndp = [-1] * (k + 1)
            
            for j in range(k + 1):
                if dp[j] > x:
                    ndp[j] = fmax(ndp[j], dp[j] - x + y)
    
            for j in range(k):
                ndp[j + 1] = fmax(ndp[j + 1], dp[j])
            
            dp = ndp
        
        outs.append('Y' if max(dp) >= 0 else 'N')
    
    print('\n'.join(outs))
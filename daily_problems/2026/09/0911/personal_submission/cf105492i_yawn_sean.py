# Submission link: https://codeforces.com/gym/105492/submission/390158068
def main():
    n, k = MII()
    
    ts = []
    fs = []
    
    for _ in range(n):
        t, f = MII()
        ts.append(t)
        fs.append(f)
    
    ps = []
    ds = []
    cs = []
    
    for _ in range(k):
        p, d, c = MII()
        ps.append(p)
        ds.append(d)
        cs.append(c)
    
    dp = [inf] * (n + 1)
    dp[0] = 0
    
    pts = [0] * k
    
    for i in range(n):
        dp[i + 1] = dp[i] + fs[i]
        
        for j in range(k):
            while ts[i] - ts[pts[j]] + 1 > ps[j] or i - pts[j] + 1 > ds[j]:
                pts[j] += 1
            
            dp[i + 1] = fmin(dp[i + 1], dp[pts[j]] + cs[j])
    
    print(dp[n])
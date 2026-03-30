# Submission link: https://codeforces.com/gym/106443/submission/368848771
def main(): 
    n = II()
    xs = []
    ys = []
    
    for _ in range(n):
        x, y = MII()
        xs.append(x)
        ys.append(y)
    
    msks = [set() for _ in range(n)]
    
    for i in range(n):
        for j in range(i):
            x1, y1 = xs[i], ys[i]
            x2, y2 = xs[j], ys[j]
            msk = 0
            
            for k in range(n):
                x, y = xs[k], ys[k]
                if (x1 - x) * (y2 - y) == (x2 - x) * (y1 - y):
                    msk |= 1 << k
            
            for k in range(n):
                if msk >> k & 1:
                    msks[k].add(msk)
    
    dp = [n] * (1 << n)
    dp[0] = 0
    
    for i in range((1 << n) - 1):
        resid = ((1 << n) - 1) ^ i
        x = (resid & -resid).bit_length() - 1
        
        for j in msks[x]:
            ni = i | j
            dp[ni] = fmin(dp[ni], dp[i] + 1)
    
    print(dp[-1])
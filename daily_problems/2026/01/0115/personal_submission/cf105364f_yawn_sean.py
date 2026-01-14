# Submission link: https://codeforces.com/gym/105364/submission/357776986
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        v = II() * 100
        a, b, c = MII()
        p1, p2, p3 = MII()
        
        def f(i, j, k):
            return (i * (p2 + 1) + j) * (p3 + 1) + k
        
        inf  = 10 ** 9
        dp = [-inf] * (p1 + 1) * (p2 + 1) * (p3 + 1)
        resid = [0] * (p1 + 1) * (p2 + 1) * (p3 + 1)
        
        for i in range(p1 + 1):
            for j in range(p2 + 1):
                for k in range(p3 + 1):
                    if (i * a + j * b + k * c) * 5 > v:
                        nx = v - (i * a + j * b + k * c) * 5
                        ny = 0
                        nmsk = f(i, j, k)
                        if dp[nmsk] < nx or (dp[nmsk] == nx and resid[nmsk] < ny):
                            dp[nmsk] = nx
                            resid[nmsk] = ny
                        
                        x = dp[nmsk]
                        y = resid[nmsk]
                        
                        if i < p1:
                            nx, ny = x, y
                            nmsk = f(i + 1, j, k)
                            
                            if ny + a < 100:
                                ny += a
                            else:
                                nx = nx + v - (ny + a) * 5
                                ny = 0
                            
                            if dp[nmsk] < nx or (dp[nmsk] == nx and resid[nmsk] < ny):
                                dp[nmsk] = nx
                                resid[nmsk] = ny
                        
                        if j < p2:
                            nx, ny = x, y
                            nmsk = f(i, j + 1, k)
                            
                            if ny + b < 100:
                                ny += b
                            else:
                                nx = nx + v - (ny + b) * 5
                                ny = 0
                            
                            if dp[nmsk] < nx or (dp[nmsk] == nx and resid[nmsk] < ny):
                                dp[nmsk] = nx
                                resid[nmsk] = ny
                        
                        if k < p3:
                            nx, ny = x, y
                            nmsk = f(i, j, k + 1)
                            
                            if ny + c < 100:
                                ny += c
                            else:
                                nx = nx + v - (ny + c) * 5
                                ny = 0
                            
                            if dp[nmsk] < nx or (dp[nmsk] == nx and resid[nmsk] < ny):
                                dp[nmsk] = nx
                                resid[nmsk] = ny
        
        outs.append(max(dp))
    
    print('\n'.join(map(str, outs)))
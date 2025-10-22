# Submission link: https://codeforces.com/gym/105582/submission/345146832
def main(): 
    n, mi, ma = MII()
    
    ms = []
    cs = []
    
    for _ in range(n):
        m, c = MII()
        ms.append(m)
        cs.append(c)
    
    M = 10 ** 4
    l, r = 1, 10 ** 6
    dp = [0] * (M + 1)
    
    while l <= r:
        mid = (l + r) // 2
        
        for i in range(M + 1):
            dp[i] = 0
        
        dp[0] = 1
        
        for i in range(n):
            m = ms[i]
            c = cs[i] // mid
            
            for j in range(m):
                bound = -1
                for x in range(j, M + 1, m):
                    if dp[x]:
                        bound = fmax(bound, x + c * m)
                    if x <= bound:
                        dp[x] = 1
        
        flg = False
        for i in range(mi, ma + 1):
            if dp[i]:
                flg = True
        
        if flg: l = mid + 1
        else: r = mid - 1
    
    print(r)
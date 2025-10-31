# Submission link: https://codeforces.com/gym/104015/submission/346411152
def main(): 
    M = 2 * 10 ** 5
    n = II()
    
    cnt1 = [0] * M
    cnt2 = [0] * M
    
    xs = []
    ys = []
    
    for _ in range(n):
        x, y = GMI()
        cnt1[x] += 1
        cnt2[y] += 1
        xs.append(x)
        ys.append(y)
    
    total = 0
    
    dp0, dp1, dp2, dp3 = 1, 0, 0, 0
    for x in cnt1:
        dp3 += dp2 * x
        dp2 += dp1 * x
        dp1 += dp0 * x
    
    total += dp3
    
    dp0, dp1, dp2, dp3 = 1, 0, 0, 0
    for x in cnt2:
        dp3 += dp2 * x
        dp2 += dp1 * x
        dp1 += dp0 * x
    
    total += dp3
    
    dup = math.comb(n, 3)
    
    for v in cnt1:
        dup -= math.comb(v, 2) * (n - v)
    
    for v in cnt2:
        dup -= math.comb(v, 2) * (n - v)
    
    for i in range(n):
        dup += (cnt1[xs[i]] - 1) * (cnt2[ys[i]] - 1)
    
    for v in cnt1: dup -= math.comb(v, 3)
    for v in cnt2: dup -= math.comb(v, 3)
    
    print(total - dup)
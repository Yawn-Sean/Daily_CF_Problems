# Submission link: https://codeforces.com/gym/104479/submission/350928014
def main(): 
    rnd = random.getrandbits(30)
    
    n = II()
    lsts = []
    vals = []
    
    for _ in range(n):
        l = II()
        nums = [x + rnd for x in MII()]
        nums.sort()    
        lsts.append(nums)
        vals.extend(nums)
    
    vals = sorted(set(vals))
    k = len(vals)
    d = {v: i for i, v in enumerate(vals)}
    
    fen = FenwickTree(k)
    ans = []
    
    for i in range(n):
        l = len(lsts[i])
        
        val = fen.rsum(d[lsts[i][0]] + 1, k - 1)
        chosen = lsts[i][0]
        
        for j in range(1, l):
            if fen.rsum(d[lsts[i][j]] + 1, k - 1) != val: break
            chosen = lsts[i][j]
    
        fen.add(d[chosen], 1)
        ans.append(chosen)
    
    st_range = sorted(range(n), key=lambda x: ans[x])
    
    last_i = n
    cur = [0]
    dp = [1]
    
    mod = 998244353
    
    for i in st_range:
        ncur = []
        ndp = []
        
        pt = 0
        res = 0
        
        l = len(lsts[i])
        for j in range(l):
            if lsts[i][j] > ans[i]: break
            
            while pt < len(cur) and (cur[pt] < lsts[i][j] or (cur[pt] == lsts[i][j] and last_i < i)):
                res += dp[pt]
                res %= mod
                pt += 1
            
            ncur.append(lsts[i][j])
            ndp.append(res)
        
        cur = ncur
        dp = ndp
        last_i = i
    
    print(sum(dp) % mod)
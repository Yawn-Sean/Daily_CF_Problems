# Submission link: https://codeforces.com/contest/75/submission/331736031
def main():
    n, m = MII()
    
    pref = []
    suff = []
    res = []
    total = []
    
    for _ in range(n):
        k, *nums = LII()
        
        cur = 0
        p = -10000
        
        for i in range(k):
            cur += nums[i]
            p = fmax(p, cur)
        
        pref.append(p)
        total.append(cur)
        
        cur = 0
        s = -10000
        
        for i in range(k - 1, -1, -1):
            cur += nums[i]
            s = fmax(s, cur)
        
        suff.append(s)
    
        cur = 0
        r = -10000
        
        for i in range(k):
            cur = fmax(cur, 0) + nums[i]
            r = fmax(cur, r)
        
        res.append(r)
    
    idxs = LGMI()
    
    ans = -10000
    
    cur = 0
    for idx in idxs:
        ans = fmax(ans, res[idx])
        ans = fmax(ans, cur + pref[idx])
        cur = fmax(cur + total[idx], suff[idx])
    
    print(ans)
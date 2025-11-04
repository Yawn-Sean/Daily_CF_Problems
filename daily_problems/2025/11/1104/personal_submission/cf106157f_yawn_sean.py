# Submission link: https://codeforces.com/gym/106157/submission/347199597
def main(): 
    n, m = MII()
    nums = LII()
    
    us = []
    vs = []
    
    for _ in range(m):
        u, v = GMI()
        if nums[u] > nums[v]:
            u, v = v, u
        us.append(u)
        vs.append(v)
    
    st_range = sorted(range(m), key=lambda x: nums[vs[x]])
    
    uf = UnionFind(n)
    
    ans = 10 ** 8
    
    for i in range(n):
        uf.init()
        
        for j in st_range:
            if nums[us[j]] >= nums[i]:
                uf.merge(us[j], vs[j])
                if uf.find(0) == uf.find(1):
                    ans = fmin(ans, nums[vs[j]] - nums[i])
                    break
    
    print(ans)
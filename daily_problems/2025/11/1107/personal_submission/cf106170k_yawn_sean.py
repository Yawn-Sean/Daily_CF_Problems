# Submission link: https://codeforces.com/gym/106170/submission/347655946
def main(): 
    n, m = MII()
    nums = LII()
    
    ls = []
    rs = []
    xs = []
    ys = []
    
    for _ in range(m):
        l, r, x, y = MII()
        ls.append(l - 1)
        rs.append(r)
        xs.append(x)
        ys.append(y)
    
    bound = 10 ** 13
    l, r = 0, bound
    sol = [0] * (n + 1)
    
    while l <= r:
        mid = (l + r) // 2
        
        for _ in range(n):
            for i in range(m):
                sol[rs[i]] = fmax(sol[rs[i]], sol[ls[i]] + xs[i])
                sol[ls[i]] = fmax(sol[ls[i]], sol[rs[i]] - ys[i])
            
            for i in range(n):
                sol[i + 1] = fmax(sol[i + 1], sol[i] + fmax(1, nums[i] - mid))
                sol[i] = fmax(sol[i], sol[i + 1] - nums[i] - mid)
    
        flg = True
    
        for i in range(n):
            if not fmax(1, nums[i] - mid) <= sol[i + 1] - sol[i] <= nums[i] + mid:
                flg = False
        
        for i in range(m):
            if not xs[i] <= sol[rs[i]] - sol[ls[i]] <= ys[i]:
                flg = False
        
        if flg: r = mid - 1
        else: l = mid + 1
        
        for i in range(n + 1):
            sol[i] = 0
    
    print(l if l < bound else -1)
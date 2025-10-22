# Submission link: https://codeforces.com/gym/105582/submission/345148213
def main(): 
    n, a, b = MII()
    nums = []
    
    for _ in range(n):
        m, t = MII()
        m *= b
        t *= b
        nums.append(m - t // b * a)
    
    k = n // 2
    cnt = Counter()
    
    def f(idx, val):
        if idx == k:
            cnt[val] += 1
            return
        f(idx + 1, val + nums[idx])
        f(idx + 1, val)
    
    f(0, 0)
    
    vals = nums[k:]
    k2 = len(vals)
    
    ans = 0
    
    def g(idx, val):
        global ans
        if idx == k2:
            if -val in cnt:
                ans += cnt[-val]
            return 
        g(idx + 1, val + vals[idx])
        g(idx + 1, val)
    
    g(0, 0)
    
    print(ans - 1)
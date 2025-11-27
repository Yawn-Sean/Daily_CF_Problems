# Submission link: https://codeforces.com/gym/105314/submission/350847509
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n, m = MII()
        nums = LII()
        nums.sort()
        
        l, r = 1, 10 ** 7
        
        while l <= r:
            mid = (l + r) // 2
            
            pt = 0
            cnt = 0
            
            for i in range(n):
                while pt < n and nums[pt] - nums[i] < mid:
                    pt += 1
                cnt += (n - pt) * 2
            
            if cnt <= m: r = mid - 1
            else: l = mid + 1
        
        acc = list(accumulate(nums, initial=0))
        
        bound = l
        pt = 0
        cnt = 0
        ans = 0
        
        for i in range(n):
            while pt < n and nums[pt] - nums[i] < bound:
                pt += 1
            cnt += (n - pt) * 2
            ans += (acc[n] - acc[pt] - (n - pt) * nums[i]) * 2
        
        ans += (m - cnt) * (bound - 1)
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))
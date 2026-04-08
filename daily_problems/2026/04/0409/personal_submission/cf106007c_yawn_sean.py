# Submission link: https://codeforces.com/gym/106007/submission/370251177
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n, m = MII()
        nums = LII()
    
        total = sum(nums)
        vis = [-1] * (total + 1)
        
        cur = 0
        for i in range(n):
            for j in range(cur + 1, cur + nums[i] + 1):
                vis[j] = i
            cur += nums[i]
        
        acc = list(accumulate(nums, initial=0))
        
        for d in range(1, m + 1):
            pt = 0
            
            while pt < n:
                pos = vis[fmin(total, acc[pt] + m - d + 1)] + 1
                if m < acc[pos] - acc[pt]: break
                pt = pos
            else:
                outs.append(d)
                break
    
    print('\n'.join(map(str, outs)))